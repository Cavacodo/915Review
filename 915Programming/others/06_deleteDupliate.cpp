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

void removeDuplicate(ListNode* h){
    unordered_set<int> uset;
    ListNode* dhead = new ListNode();
    dhead->next = h;
    ListNode* slow = dhead;
    ListNode* fast = h;
    while(fast != nullptr){
        if(uset.count(fast->val) == 0){
            uset.insert(fast->val);
        }else{
            ListNode* tmp;
            if(fast->next != nullptr){
                tmp = fast->next;
                slow->next = tmp;
                fast = tmp;
                if(fast) fast = fast->next;
            if(slow) slow = slow->next;
            }else{
                slow->next = nullptr;
                return ;
            }
        }
    }
} 
int main()
{
    vector<int> v = {1,2,3,4,5,5,5,6,7,7,8};
    ListNode* head = new ListNode();
    head = head->generateList(v);
    removeDuplicate(head);
    return	0;
}