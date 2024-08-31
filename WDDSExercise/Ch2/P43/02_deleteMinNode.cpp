#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 }; //  好定义

void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

 int deleteMinNode(ListNode* head){
    ListNode* cur = head;
    ListNode* pre = nullptr;
    ListNode* minNode = cur;
    ListNode* minPre = pre;
    int min = INT_MAX;
    while(cur != nullptr){
        if(min > cur->val){
            min = cur->val;
            minNode = cur;
            minPre = pre;
        }
        pre = cur;
        cur = cur->next;
    }
    int ans = minNode->val;
    minPre->next = minNode->next;
    free(minNode);
    return ans;
 }

int main()
{
    ListNode* l1 = new ListNode(8);
    ListNode* l2 = new ListNode(5,l1);
    ListNode* l3 = new ListNode(2,l2);
    ListNode* l4 = new ListNode(10,l3);
    printList(l4);
    cout << deleteMinNode(l4) << endl;
    printList(l4);
    return	0;
}