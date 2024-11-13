// TODO 不使用外部空间
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    char val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(char x) : val(x), next(nullptr) {}
    ListNode(char x, ListNode *next) : val(x), next(next) {}
    ListNode* generateList(vector<char> arr){
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for(int i = 1; i < arr.size(); i++){
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }
};
ListNode *ab, *nums, *others;
ListNode *cab,*cnum,*cothers;
void findSame(ListNode* r){
    ListNode* cur = r;
    while(cur){
        if(cur->val <= 'Z' && cur->val >= 'A'){
            ListNode* fcur = cur;
            while(fcur && fcur->val <= 'Z' && fcur->val >= 'A'){
                fcur = fcur->next;
            }
            cab->next = cur;
            cur = fcur;
        }
        if(cur->val <= '9' && cur->val >= '0'){
            ListNode* fcur = cur;
            while(fcur && fcur->val <= '9' && fcur->val >= '0'){
                fcur = fcur->next;
            }
            cab->next = cur;
            cur = fcur;
        }
    }
} 

int main()
{
    
    return	0;
}