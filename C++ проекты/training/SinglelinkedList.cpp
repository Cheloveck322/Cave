#include <iostream>

struct Node
{
    int m_data{ 0 };
    Node* m_next{ nullptr };

    Node() : m_data{ 0 }, m_next{ nullptr } {}
    Node(int data) : m_data { data }, m_next { nullptr } {}
    Node(int data, Node* next) : m_data { data }, m_next { next } {}
};

bool searchingInList(Node* head, int find)
{
    while (head != nullptr)
    {
        if (head->m_data == find)
            return true;
        head = head->m_next;
    } 
    return false;
}

int lengthList(Node* head)
{
    int length {};
    while (head != nullptr)
    {   
        ++length;
        head = head->m_next;
    }
    return length;
}

void printList(Node* head)
{
    Node* curr { head };
    
    while(curr != nullptr)
    {
        std::cout << curr->m_data << ' ';
        curr = curr->m_next;
    }
    std::cout << '\n';
}

void insertAtBegin(Node** head, int data)
{
    Node* newNode { new Node(data) };

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }
    
    newNode->m_next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data)
{
    Node* newNode { new Node(data) };
    Node* curr { *head };

    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    while (curr->m_next != nullptr)
    {
        curr = curr->m_next;
    }

    curr->m_next = newNode;
}

void insertAtsomePosition(Node** head, int position, int data)
{
    Node* newNode { new Node(data) };
    Node* curr { *head };

    if (*head == nullptr || position == 0)
    {
        newNode->m_next = *head;
        *head = newNode;
        return;
    }

    for (int i { 1 }; i < position - 1 && curr->m_next != nullptr; ++i)
    {
        curr = curr->m_next;
    }
    newNode->m_next = curr->m_next;
    curr->m_next = newNode;
}

void removeFirstNode(Node* head)
{
    
    if (head == nullptr)
    {
        std::cout << "List is empty. Nothing happaned.\n";
        return;
    }
    Node* curr { head };
    head = head->m_next;
    delete head;
}

int main()
{
    Node* third { new Node{3} };
    Node* second { new Node{2, third} };
    Node* head { new Node{1, second} };

    
    insertAtEnd(&head, 5);
    insertAtsomePosition(&head, 3, 6);
    std::cout << std::boolalpha << searchingInList(head, 3) << '\n';
    std::cout << lengthList(head) << '\n';
    removeFirstNode(head);
    printList(head);

    delete head;
    delete second; 
    delete third; 
    
    return 0;
}