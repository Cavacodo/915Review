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
bool isSymmertic(ListNode* head){
    deque<int> dq;
    while(head != nullptr){
        dq.push_back(head->val);
        head = head->next;
    }
    int r = dq.size() - 1;
    for(int i =  0; i < dq.size()/2; i++){
        if(dq[i] != dq[r--]) return false;
        return true;
    }
}
int main()
{
    vector<int> v = {1,2,3,4,5,6,5,4,3,2,1};
    ListNode* head = new ListNode();
    head = head->generateList(v);
    cout << isSymmertic(head) << endl;
    return	0;
}