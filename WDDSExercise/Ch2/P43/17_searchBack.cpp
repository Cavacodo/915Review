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

int searchBack(ListNode* head,int k){
    deque<ListNode*> dq;
    while(head != nullptr){
        dq.push_back(head);
        head = head->next;
    }
    if(k > dq.size()) return 0;
    k--;
    while(k--){
        dq.pop_back();
    }
    cout << dq.back()->val << endl;
    return 1;
}

int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8};
    ListNode *head = head->generateList(a);
    cout << searchBack(head,10) << endl;
    return	0;
}