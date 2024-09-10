// 稀疏矩阵的两种存储方式
// 三元组和十字链表
#include <bits/stdc++.h>
using namespace std;
#define num 100

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

// 十字链表节点定义
typedef struct OLNode
{
    int i , j;  //行标，列标
    int data;   //值域
    OLNode *row_next, *col_next; // 指向同行同列的下一个节点
};
typedef struct
{   
    ListNode *rhead, *chead;    //行列的表头指针 这里指向的应该是OLNode
    int mu,nu,tu; //行数，列数，非零元素个数

}CrossList;

//三元组
typedef struct
{
    int i , j;
    int data;
}triple;

typedef struct 
{
    triple data[num];
    int m,n,nzero;  //  记录行数，列数，非零元素个数
    // 注意这里存储是有序存储，如从行开始存，则一定是按照行升序存储的
}TSMatrix;




int main()
{
    
    
    return	0;
}