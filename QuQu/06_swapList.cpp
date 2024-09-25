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

ListNode* solve(ListNode* l){
    ListNode* pre = nullptr;
    ListNode* cur = l;
    while(cur){
        ListNode* tmp = cur;
        cur = cur->next;
        tmp->next = pre;
        pre = tmp;
    }
    return pre;
}

int main()
{
    ListNode* l = new ListNode(0);
    vector<int> v = {1,2,3,4,5,6};
    l->next = l->generateList(v);
    ListNode* ans = solve(l);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
    return	0;
}