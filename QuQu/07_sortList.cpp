#include <bits/stdc++.h>
using namespace std;

// 排序无序链表
// 要求O(nlogn)
// 快排或者Merge Sort
// TODO 看一下排序无序链表
// leetcode 148排序链表
// leetcode 86 分隔链表

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode *generateList(vector<int> arr)
    {
        ListNode *head = new ListNode(arr[0]);
        ListNode *cur = head;
        for (int i = 1; i < arr.size(); i++)
        {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }
};

// QuickSort
ListNode* solve(ListNode* head, ListNode* pend){
    if(!head||head->next==pend) return head;
    int val = head->val;
    ListNode* p = head;
    ListNode* q = p->next;
    while(q!=pend){
        if(q->val < val){
            p = p->next;
            swap(p->val, q->val);
        }
        q = q->next;
    }
    swap(head->val, p->val);
    return p;
}
 
//快排
void quick_sort(ListNode* head, ListNode* pend){
    if(head==pend) return;
    ListNode* p = solve(head, pend);
    quick_sort(head, p);
    quick_sort(p->next, pend);
}
//对指定链表进行快排
ListNode* sortInList(ListNode* head) {
    quick_sort(head, NULL);
    return head;
}

// merge sort
ListNode *merge(ListNode *head1, ListNode *head2);
ListNode* MergeSort(ListNode *head, ListNode *tail)
{
    if (head == nullptr)
    {
        return head;
    }
    if (head->next == tail)
    {
        head->next = nullptr;
        return head;
    }
    ListNode *slow = head, *fast = head;
    while (fast != tail)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail)
        {
            fast = fast->next;
        }
    }
    ListNode *mid = slow;
    return merge(MergeSort(head, mid), MergeSort(mid, tail));
}

ListNode *merge(ListNode *head1, ListNode *head2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->val <= temp2->val)
        {
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != nullptr)
    {
        temp->next = temp1;
    }
    else if (temp2 != nullptr)
    {
        temp->next = temp2;
    }
    return dummyHead->next;
}

int main()
{
    ListNode *head = new ListNode(9);
    vector<int> v = {2, 4, 7, 1, 3, 5, 7};
    head->next = head->generateList(v);
    ListNode *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    quick_sort(head, nullptr);
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}