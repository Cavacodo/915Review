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

int maxPairSum(ListNode* head){
    deque<ListNode*> dq;
    ListNode* cur = head;
    while(cur != nullptr){
        dq.push_back(cur);
        cur = cur->next;
    }
    int mx = INT_MIN;
    while(!dq.empty()){
        int tmp = dq.front()->val + dq.back()->val;
        mx = max(tmp,mx);
        dq.pop_back();
        dq.pop_front(); 
    }
    return mx;
}

int main()
{
    vector<int> a = {1,5,2,3,6,9,10,2};
    ListNode *head = head->generateList(a);
    cout << maxPairSum(head) << endl;
    return	0;
}