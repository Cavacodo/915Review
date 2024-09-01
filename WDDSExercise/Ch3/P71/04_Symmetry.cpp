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

bool isSymmetry(ListNode *head){
    deque<int> dq;
    while(head != nullptr){
        dq.push_back(head->val);
        head = head->next;
    }
    while(!dq.empty()){
        if(dq.front() == dq.back()){
            dq.pop_front();
            if(!dq.empty()) dq.pop_back();
        }
        else return 0;
    }
    return 1;
}

int main()
{
    vector<int> a = {1,2,3,3,2,1};
    vector<int> b = {1,2,3,2,1};
    vector<int> c = {1,2,3};
    ListNode* h1 = h1->generateList(a);
    ListNode* h2 = h2->generateList(b);
    ListNode* h3 = h3->generateList(c);
    cout << isSymmetry(h1) << endl;
    cout << isSymmetry(h2) << endl;
    cout << isSymmetry(h3) << endl;
    return	0;
}