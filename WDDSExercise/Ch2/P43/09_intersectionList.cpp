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

ListNode* intersectList(ListNode* l1,ListNode *l2){
    ListNode *c1 = l1, *c2 = l2;
    vector<ListNode*> ans;
    while(c1 != nullptr && c2 != nullptr){
        while(c1 != nullptr && c1->val < c2->val) c1 = c1->next;
        if(c1->val == c2->val){
            ans.push_back(c1);
            c1 = c1->next;
            if(c1 == nullptr) break;
        }
        while(c2 != nullptr && c2->val < c1->val) c2 = c2->next;
        if(c1->val == c2->val){
            ans.push_back(c1);
            c2 = c2->next;
            if(c2 == nullptr) break;
        }
    }
    ListNode* a = ans[0];
    ListNode *cur = a;
    for(int i = 1; i < ans.size(); i++){
        cur->next = ans[i];
        cur = cur->next;
    }
    cur->next = nullptr;
    return a;
}
int main()
{
    vector<int> arr1 = {1,2,3,4,5,6,7};
    vector<int> arr2 = {3,4,5,7};
    ListNode* t = t->generateList(arr1);
    ListNode* t1 = t1->generateList(arr2);
    printList(t);
    printList(t1);
    ListNode* ans = intersectList(t,t1);
    printList(ans);
    return	0;
}