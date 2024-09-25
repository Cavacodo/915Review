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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        vector<ListNode*> s;
        vector<ListNode*> b;
        ListNode* cur = head;
        while(cur != nullptr){
            if(cur->val < x){
                s.push_back(cur);
            }else b.push_back(cur);
            cur = cur->next;
        }
        if(s.empty()) return b.front();
        else if(b.empty()) return s.front();
        ListNode* l1 = s.front();
        ListNode* l2 = b.front();
        cur = l1;
        for(int i = 1; i < s.size(); i++){
            cur->next = s[i];
            cur = cur->next;
        }
        cur->next = l2;
        cur = l2;
        for(int i = 1; i < b.size(); i++){
            cur->next = b[i];
            cur = cur->next;
        }
        cur->next = nullptr;
        return l1;
    }
};


int main()
{
    
    return	0;
}