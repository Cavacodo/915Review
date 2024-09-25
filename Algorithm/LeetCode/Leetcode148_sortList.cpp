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
    ListNode* partition(ListNode* head,ListNode* tail) {
        if(head == nullptr) return head;
        int x = head->val;
        if(!head) return head;
        vector<ListNode*> s;
        vector<ListNode*> b;
        ListNode* cur = head;
        while(cur != tail && cur != nullptr){
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
        cur->next = tail;
        return l1;
    }
    void QuickSort(ListNode* head,ListNode* tail){
        if(head == tail) return;
        ListNode* pivot = partition(head,tail);
        QuickSort(head,pivot);
        QuickSort(pivot->next,tail);
    }
    ListNode* sortList(ListNode* head) {
        QuickSort(head,nullptr);
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode* head = new ListNode(4);
    head->next = head->generateList(vector<int> {2,1,3,5});
    sol.sortList(head);
    return	0;
}