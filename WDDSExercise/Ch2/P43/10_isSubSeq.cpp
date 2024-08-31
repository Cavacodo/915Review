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
//TODO KMP前缀优化
bool isSubSeq(ListNode* l1,ListNode *l2){
    ListNode *l = l1, *r = l2;
    vector<ListNode*> v;
    while(l != nullptr){
        if(l->val == l2->val) v.push_back(l);
        l = l->next;
    }
    for(int i = 0; i < v.size(); i++){
        ListNode *cur = v[i];
        while(cur != nullptr && cur->val == r->val){
            cur = cur->next;
            r = r->next;
        }
        if(r == nullptr) return 1;
        r = l2;
    }
    return 0;
}

int main()
{
    vector<int> v1 = {1,2,1,2,3};
    vector<int> v2 = {1,2,3};
    ListNode *l1 = l1->generateList(v1);
    ListNode *l2 = l2->generateList(v2);
    cout << isSubSeq(l1,l2) << endl;
    return	0;
}