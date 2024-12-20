/*
    单链表
*/
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
private:
    int data;
    ListNode* next;
public:
    //构造方法后面的;可加可不加
    ListNode() : data(0),next(nullptr) {};
    ListNode(int val) : data(val), next(nullptr) {};
    int getVal(){
        return data;
    }
    ListNode getNext(){
        if(next == nullptr) return NULL;
        return *next;
    }
    void setNext(ListNode* ll){
        next = ll;
    }
    void display(){
        ListNode* cur = this;
        while(cur != nullptr){
            cout << cur->getVal() << "->";
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }
};

ListNode* dummyHead = new ListNode();

// void addHead(ListNode* ll){
//     ListNode cur;
//     if(&dummyHead->getNext() != nullptr){
//         cur = dummyHead->getNext();
//         ll->setNext(&cur);
//     }
//     dummyHead->setNext(ll);
// }
//TODO Debugging
int main(){
    ListNode a = dummyHead->getNext();
    ListNode* n0 = new ListNode();
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    n0->setNext(n1);
    n1->setNext(n2);
    n2->setNext(n3);
    // addHead(n0);
    dummyHead->display();
    delete n0;
    delete n1;
    delete n2;
    delete n3;
    return 0;
}