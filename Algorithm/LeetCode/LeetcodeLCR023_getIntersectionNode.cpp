// 找寻两个链表的交点
// 1.使用set O(m+n)
// 2.
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        ListNode* a = headA, *b = headB;
        while(a != NULL){
            set.insert(a);
            a = a->next;
        }
        while(b != NULL){
            if(set.count(b)) return b;
            else b = b->next;
        }
        return NULL;
    }
};
int main()
{
    
    
    return	0;
}