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

ListNode *ll1, *ll2;
void splitList(ListNode* head){
    ll1 = head,ll2 = head->next;
    ListNode *cur = head;
    while(cur->next != nullptr){
        ListNode *t = cur->next;
        cur->next = t->next;
        cur = t;
    }
}

int main()
{
    ListNode* l1 = new ListNode(8);
    ListNode* l2 = new ListNode(5,l1);
    ListNode* l3 = new ListNode(2,l2);
    ListNode* l4 = new ListNode(10,l3);
    ListNode* l5 = new ListNode(3,l4);
    ListNode* l6 = new ListNode(4,l5);
    ListNode* l7 = new ListNode();
    l7->next = l6;
    printList(l7);
    splitList(l7);
    printList(ll1);
    printList(ll2);
    return	0;
}