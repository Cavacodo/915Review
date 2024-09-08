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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int cnt = 0;
        while(cur){
            cnt++;
            cur = cur->next;
        }
        if(n == cnt) return head->next;
        cur = head;
        int idx = 1;
        ListNode* pre;
        while(cur){
            if(idx == cnt-n) pre = cur;
            if(idx == cnt-n+1){
                pre->next = cur->next;
                return head;
            }
            idx++;
            cur = cur->next;
        }
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(0);
    Solution sol;
    sol.removeNthFromEnd(head,1);
    return	0;
}