#include <iostream>
#include <algorithm>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head) 
{
    int max { head->val };
    ListNode* prev{ head };
    while (head->next)
    {
        ListNode* curr{ head };
        int currentValue { head->val };
        int prevValue { prev->val };
        int nextValue { head->next->val };
        if (max < nextValue)
        {
            max = nextValue;
            std::free(curr);
        }
        if (currentValue < nextValue && curr)
        {
            prev->next = curr->next;
            std::free(curr);
        }
        head = head->next;
        prev = curr;
    }
}

void printList(ListNode* head)
{
    while (head->next != nullptr)
        std::cout << head++ << ' ';
    std::cout << '\n';
}

ListNode* fullFillList(ListNode* head, int value)
{
    if (value == 0)
        return head;

    head->val = value;
    return head++;
}

int main()
{
    ListNode head{ 5 };
    ListNode second { 3 };
    ListNode third { 1 };
    int value{};

    while(head.next != nullptr)
    {
        std::cout << "Enter a value (0 to break): ";
        std::cin >> value;
        fullFillList(&head, value);
    }
    printList(&head);

    return 0;
}