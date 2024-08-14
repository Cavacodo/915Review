#include <bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int data;
    struct TreeNode *L,*R;
}Node,*Tree;

void InitTree(Tree &t){
    Node *m = (Node*)malloc(sizeof(Node));
    t = m;
    t->data = 0;
    t->L = nullptr;
    t->R = nullptr;
}
//0为左，1为右
bool addNode(Node *node,int x,int direction){
    if(node == nullptr) return false;
    Node *t = (Node*)malloc(sizeof(Node));
    t->data = x;
    if(direction == 0){
        if(node->L != nullptr) return false;
        node->L = t;
    }else{
        if(node->R != nullptr) return false;
        node->R = t;
    }
    t->L = nullptr;
    t->R = nullptr;
    return true;
}
void preOrder(Node *t){
    if(t == nullptr) return;
    cout << t->data << "\t";
    if(t->L != nullptr) preOrder(t->L);
    if(t->R != nullptr) preOrder(t->R);
}
void inOrder(Node *t){
    if(t == nullptr) return;
    if(t->L != nullptr) inOrder(t->L);
    cout << t->data << "\t";
    if(t->R != nullptr) inOrder(t->R);
}
void postOrder(Node *t){
    if(t == nullptr) return;
    if(t->L != nullptr) postOrder(t->L);
    if(t->R != nullptr) postOrder(t->R);
    cout << t->data << "\t";
}
// bool removeNode(Node)

void LevelOrder(Tree t){
    deque<Node*> dq;
    dq.push_back(t);
    while(!dq.empty()){
        int size = dq.size();
        while(size--){
            Node *tmp = dq.front();
            dq.pop_front();
            if(tmp->L != nullptr) dq.push_back(tmp->L);
            if(tmp->R != nullptr) dq.push_back(tmp->R);
            cout << tmp->data << "\t";
        }
        cout << endl;
    }
}
//TODO 差一个节点删除
int main()
{
    Tree t;
    InitTree(t);
    addNode(t,1,0);
    addNode(t,2,1);
    addNode(t->L,3,0);
    addNode(t->L->L,4,0);
    LevelOrder(t);
    preOrder(t);
    cout << endl;
    inOrder(t);
    cout << endl;
    postOrder(t);
    return	0;
}