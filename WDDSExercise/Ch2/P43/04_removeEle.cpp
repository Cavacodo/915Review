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

void removeElement(ListNode *head,int l,int r){
    ListNode *cur = head->next;
    unordered_set<ListNode*> set;
    while(cur != nullptr){
        if(cur->val >= l && cur->val <= r) set.insert(cur);
        cur = cur->next;
    }
    cur = head;
    while(cur != nullptr){
        if(set.count(cur->next)){
            ListNode *t = cur->next;
            while(set.count(t) && t != nullptr) t = t->next;
            cur->next = t;
        }
        cur = cur->next;
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
    removeElement(l7,3,5);
    printList(l7);
    return	0;
}