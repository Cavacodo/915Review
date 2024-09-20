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
};
//查找倒数第k个节点的值
// O(N)
void findTail(ListNode* head,int k){
    deque<ListNode*> dq;
    ListNode* cur = head;
    while(cur != nullptr){
        dq.push_back(cur);
        cur = cur->next;
    }
    int t;
    while(k--){
        t = dq.back()->val;
        dq.pop_back();
    }
    cout << t << endl;
}

int main()
{
    ListNode* head = new ListNode(0);
    vector<int> arr = {1,2,3,4,5,6};
    head->next = head->generateList(arr);
    findTail(head,1);
    return	0;
}