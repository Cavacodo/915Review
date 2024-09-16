// 反转链表
// 1.采用辅助空间
// 2.直接反转
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 }; //  好定义
public:
    ListNode* reverseList1(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        deque<ListNode*> dq;
        while(head != nullptr){
            dq.push_back(head);
            head = head->next;
        }
        ListNode* nhead = dq.back();
        ListNode* cur = nhead;
        dq.pop_back();
        while(!dq.empty()){
            ListNode* t = dq.back();
            dq.pop_back();
            cur->next = t;
            cur = cur->next;
        }
        cur->next = nullptr;
        return nhead;
    }
    // 直接不使用辅助空间
    ListNode* reverseList2(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr){
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main()
{
    
    
    return	0;
}

