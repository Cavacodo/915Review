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

int main()
{
    ListNode* head = new ListNode(0);
    ListNode* h2 = new ListNode(2);
    head->next = h2;
    cout << head->next << endl;
    cout << &h2 << endl;    // 永远存放的是栈中的地址，指针的指针
    cout << &head << endl;
    return	0;
}