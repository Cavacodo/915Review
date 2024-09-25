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

ListNode* findCommon(ListNode* l1,ListNode *l2){
    unordered_set<ListNode*> set;
    ListNode* cur = l1;
    while(l1 != nullptr){
        set.insert(l1);
        l1 = l1->next;
    }
    cur = l2;
    while(cur != nullptr && !set.count(cur)){
        cur = cur->next;
    }
    return cur;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(1);
    l2->next = l1->next;
    cout << findCommon(l1,l2)->val << endl;
    return	0;
}