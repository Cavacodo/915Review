// Leetcode LCR22.检查有无环
//  1.把所有节点放在数组中，每次加入新节点时检查有无重复，时间复杂度高(//HashMap优化)
//  2.快慢指针 这是个数学问题，不用刻意记
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
bool check(ListNode* node,vector<ListNode*> &dq){
    for(auto i : dq){
        if(i == node) return 0;
    }
    return 1;
}
public:
    ListNode *detectCycle1(ListNode *head) {
        vector<ListNode*> dq;
        if(head == NULL) return head;
        ListNode* cur = head;
        while(cur != NULL){
            if(check(cur,dq)){
                dq.push_back(cur);
                cur = cur->next;
            }
            else return cur;
        }
        return NULL;
    }
    ListNode *detectCycle_opt(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head != NULL){
            if(set.find(head) != set.end()) return head;    // 也可以使用set.count()
            set.insert(head);
            head = head->next;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast,*slow;
        fast = head;
        slow = head;
        if(head == NULL) return head;
        while(fast != NULL){
            slow = slow->next;
            if(fast->next == NULL) return NULL;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* ptr = head;
                while(ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};

int main()
{
    
    
    return	0;
}