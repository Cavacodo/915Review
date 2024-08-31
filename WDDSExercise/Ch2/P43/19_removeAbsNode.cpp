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

void removeAbsNode(ListNode* head){
    unordered_set<int> set;
    ListNode *pre = nullptr, *cur = head;
    while(cur != nullptr){
        if(!set.count(abs(cur->val))){
            set.insert(abs(cur->val));
            pre = cur;
            cur = cur->next;
        }else{
            while(cur != nullptr && set.count(abs(cur->val))){
                cur = cur->next;
            }
            pre->next = cur;
            if(cur == nullptr) return;
            pre = cur;
            cur = cur->next;
        }
    }
}

int main()
{
    vector<int> a = {0,21,-15,15,-7,15};
    ListNode* head = head->generateList(a);
    printList(head);
    removeAbsNode(head);
    printList(head);
    return	0;
}