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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        while(l1 != nullptr && l2 != nullptr){
            int tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            tmp %= 10;
            ListNode* nt = new ListNode(tmp);
            cur->next = nt;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            int tmp = carry + l1->val;
            carry = tmp / 10;
            tmp %= 10;
            ListNode* nt = new ListNode(tmp);
            cur->next = nt;
            cur = cur->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int tmp = carry + l2->val;
            carry = tmp / 10;
            tmp %= 10;
            ListNode* nt = new ListNode(tmp);
            cur->next = nt;
            cur = cur->next;
            l2 = l2->next;
        }
        if(carry != 0){
            ListNode* nt = new ListNode(carry);
            cur->next = nt;
        }
        return ans->next;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = {2,4,9};
    vector<int> v2 = {5,6,4,9};
    ListNode* l1 = new ListNode();
    l1 = l1->generateList(v1);
    ListNode* l2 = new ListNode();
    l2 = l2->generateList(v2);
    ListNode* ans = sol.addTwoNumbers(l1,l2);
    return	0;
}