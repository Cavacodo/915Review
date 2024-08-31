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

ListNode* commonNode(ListNode* h1,ListNode *h2){
    ListNode *cur = h1;
    unordered_set<ListNode*> set;
    while(cur != nullptr){
        set.insert(cur);
        cur = cur->next;
    }
    cur = h2;
    while(cur != nullptr){
        if(set.count(cur)) return cur;
        cur = cur->next;
    }
    return new ListNode();
}

int main()
{
    
    
    return	0;
}