#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 }; //  好定义

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head){
    ListNode *cur = head, *pre = nullptr;
    while(cur != nullptr){
        ListNode *n = cur->next;
        cur->next = pre;
        pre = cur;
        cur = n;
    }
    return pre;
}

int main()
{
    ListNode* l1 = new ListNode(8);
    ListNode* l2 = new ListNode(5,l1);
    ListNode* l3 = new ListNode(2,l2);
    ListNode* l4 = new ListNode(10,l3);
    printList(l4);
    ListNode *t = reverseList(l4);
    printList(t);
    return	0;
}