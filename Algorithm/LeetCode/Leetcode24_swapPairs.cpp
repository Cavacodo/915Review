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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        if(!head || !head->next) return dummy->next;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur->next){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = cur;
            pre->next = tmp;
            pre = cur;
            cur = cur->next;
            if(!cur) break;
        }
        return dummy->next;
    }   
};

int main()
{
    
    
    return	0;
}