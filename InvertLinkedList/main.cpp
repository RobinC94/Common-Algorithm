#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* InvertListNode(ListNode *head)
{
    if(head == NULL)
        return NULL;
    ListNode* n = head;
    head = head->next;
    n->next = NULL;
    while(head != NULL)
    {
        ListNode* tmp = head->next;
        head->next = n;
        n = head;
        head = tmp;
    }
    return n;
}

void Display(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode *node = new ListNode(1);
    node->next = new ListNode(2);
    ListNode *node2 = node->next;
    node2->next = new ListNode(3);
    Display(node);
    node = InvertListNode(node);
    Display(node);
    return 0;

}