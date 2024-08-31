#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode* generateList(vector<int> arr){
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for(int i = 1; i < arr.size(); i++){
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }
 }; //  好定义

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

bool hasCycle(ListNode* head){
    unordered_set<ListNode*> set;
    while(head != nullptr && !set.count(head)){
        set.insert(head);
        head = head->next;
    }
    return head == nullptr ? 0 : 1;
}

int main()
{ 
    vector<int> a = {1,2,3,4,5};
    ListNode* h = h->generateList(a);
    cout << hasCycle(h) << endl; 
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2,l1);
    ListNode* l3 = new ListNode(3,l2);
    ListNode* l4 = new ListNode(5,l3);
    l1->next = l2;
    cout << hasCycle(l4) << endl;
    return	0;
}