#include <iostream>

struct Node
{
    int data{};
    Node* next{ nullptr };
    Node* prev{ nullptr };

    Node(int x): data { x }, next { nullptr }, prev { nullptr } {}
    Node(int x, Node* nex, Node* pre): data{ x }, next{ nex }, prev{ pre } {}
};

void forwardTraverse(Node* head)
{
    Node* curr{ head };
    if (head == nullptr)
    {
        std::cout << "List is empty.\n";
        return;
    }

    while(curr != nullptr)
    {
        std::cout << curr->data << ' ';
        curr = curr->next;
    }
    std::cout << '\n';
}

void backwardTraverse(Node* head)
{
    Node* curr{ head };
    if (head == nullptr)
    {
        std::cout << "List is empty.\n";
        return;
    }

    while (curr != nullptr)
    {
        std::cout << curr->data << ' ';
        curr = curr->prev;
    }
    std::cout << '\n';
}

int main()
{
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    std::cout << "Forward Traversal: " << '\n';
    forwardTraverse(head);

    std::cout << "Backward Traversal: " << '\n';
    backwardTraverse(third);

    delete head;
    delete second;
    delete third;    

    return 0;
}