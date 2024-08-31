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

void removeDuplicate(ListNode* head){
    unordered_set<int> set;
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while(cur != nullptr){
        if(set.count(cur->val)){
            ListNode *t = cur;
            cur = cur->next;
            pre->next = cur;
            continue;
        }else{
            set.insert(cur->val);
        }
        pre = cur;
        cur = cur->next;
    }
}

int main()
{
    ListNode* l1 = new ListNode(70);
    ListNode* l2 = new ListNode(51,l1);
    ListNode* l3 = new ListNode(42,l2);
    ListNode* l4 = new ListNode(42,l3);
    ListNode* l5 = new ListNode(42,l4);
    ListNode* l6 = new ListNode(30,l5);
    ListNode* l7 = new ListNode(21,l6);
    ListNode* l8 = new ListNode(10,l7);
    ListNode* l9 = new ListNode(10,l8);
    ListNode* l10 = new ListNode(7,l9);
    printList(l10);
    removeDuplicate(l10);
    printList(l10);
    return	0;
}