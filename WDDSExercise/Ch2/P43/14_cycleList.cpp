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

void cycleList(ListNode* head,int k){
    ListNode *cur = head;
    deque<int> dq;
    while(cur != nullptr){
        dq.push_back(cur->val);
        cur = cur->next;
    }
    cur = head;
    while(k--){
        int i = dq.back();
        dq.pop_back();
        dq.push_front(i);
    }
    int idx = 0;
    while (cur != nullptr)
    {
        cur->val = dq[idx++];
        cur = cur->next;
    }
    
}
int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8};
    ListNode *head = head->generateList(a);
    printList(head);
    cycleList(head,3);
    printList(head);
    return	0;
}