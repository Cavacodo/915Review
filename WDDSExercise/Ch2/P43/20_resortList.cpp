// TODO 这题蛮好的
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
 }; //  好定义

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}
ListNode* reverseList(ListNode* head);
// 要求不使用额外空间
void resortList(ListNode* head){
    if(head->next == nullptr) return;
    ListNode* cur = head->next;
    ListNode* pre = head;
    while(cur != nullptr){
        cur = reverseList(cur);
        pre->next = cur;
        pre = cur;
        cur = cur->next;
    }
}
ListNode* reverseList(ListNode* head){
    ListNode *pre = nullptr, *cur = head;
    while(cur != nullptr){
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre; 
}
ListNode* resortList_opt(ListNode* head){
    ListNode *h,*p,*mid;
    ListNode *slow,*fast;
    // 获取链表中间节点的快慢指针方法
    slow = head,fast = head;
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == nullptr) break;
    }
    mid = slow;
    p = reverseList(mid);
    ListNode *x = p;
    h = head;
    while(p != slow){
        ListNode *tp = p->next, *th = h->next;
        h->next = p;
        p->next = th;
        h = th;
        p = tp;
    }
    return head;
}
int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8};
    ListNode *head = head->generateList(a);
    printList(head);
    resortList_opt(head);
    printList(head);
    return	0;
}