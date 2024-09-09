// 使用递归方法反转链表
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

// 返回的tmp是最后一个元素
// 然后退出栈时每次都把head下一个元素指的下一项指向head,head下一项指向空
// 然后向前退一个head，最后会穿起来
// 难想
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* tmp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tmp;
    }
};

int main()
{
    
    
    return	0;
}