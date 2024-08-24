// 在一个链表中删除最小值的节点
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 }; //  好定义
void removeMinNode(ListNode* head){
    ListNode *cur = head, *pre = nullptr, *min = head;
    while(cur != nullptr){
        if(cur->next != nullptr && cur->next->val < min->val){
            pre = cur;
            min = cur->next;
        }
        cur = cur->next;
    }
    pre->next = min->next;
    free(min);
}
void showList(ListNode* head){
    ListNode* cur = head;
    while(cur != nullptr){
        cout << cur->val << "  ";
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    ListNode* head = new ListNode(9);
    head->next = new ListNode(7);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(8);
    showList(head);
    removeMinNode(head);
    showList(head);
    return	0;
}
