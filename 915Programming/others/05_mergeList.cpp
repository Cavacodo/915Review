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

ListNode* merge_List(ListNode* l1,ListNode* l2){
    ListNode* ans = new ListNode();
    ListNode* cur = ans;
    unordered_map<int,bool> umap;
    ListNode* tmp = l1;
    while(tmp != nullptr){
        umap[tmp->val] = true;
        tmp = tmp->next;
    }
    tmp = l2;
    while(tmp != nullptr){
        if(umap.count(tmp->val)){
            cur->next = new ListNode(tmp->val);
            cur = cur->next;
        }
        tmp = tmp->next;
    }
    return ans;
}

int main()
{
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    vector<int> v = {1,2,3,4,5,6,7};
    vector<int> v2 = {3,4,5,6,7};
    l1 = l1->generateList(v);
    l2 = l2->generateList(v2);
    ListNode* l;
    l = merge_List(l1,l2);
    return	0;
}