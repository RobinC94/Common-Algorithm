#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* InvertListNode(ListNode *head, int k)
{
    if(head == NULL)
        return NULL;
    if(k <= 1)
        return head;
    ListNode* n = head;
    ListNode* ori = head;
    head = head->next;
    n->next = NULL;
    int num = 1;
    while(num < k)
    {
        ListNode* tmp = head->next;
        head->next = n;
        n = head;
        head = tmp;
        num++;
    }
    ori->next = head;
    return n;
}

void Display(ListNode *head)
{
    head = head->next;
    while (head != NULL)
    {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    int num;
    string nums;
    int len = 0;
    getline(cin, nums);
    istringstream istr(nums);
    while (istr >> num){
        tmp -> next = new ListNode(num);
        tmp = tmp->next;
        ++len;
    }
    int k;
    cin >> k;
    if(k <= 1){
        Display(head);
        return 0;
    }
    tmp = head -> next;
    ListNode* pre = head;
    while(len >= k){
        len -= k;
        tmp = InvertListNode(tmp, k);
        pre->next = tmp;
        for(int i = 0; i < k; ++i){
            pre = pre->next;
        }
        tmp = pre->next;
    }

    Display(head);
    return 0;
}