#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int value;
    struct Node *left,*right;
}Node,*Root;
Root r;
Node createNode(int val){
    Node* t = (Node*)malloc(sizeof(Node));
    t->value = val;
    t->left = nullptr;
    t->right = nullptr;
    return *t;
}
Node* searchTree(Node* n,int key){
    while(n != nullptr && key != n->value){
        if(key < n->value) n = n->left;
        else n = n->right;
    }
    return n;
}
bool insertNode(Root &r,int key){
    if(r == NULL){
        r = (Node*)malloc(sizeof(Node));
        r->value = key;
        r->left = NULL;
        r->right = NULL;
        return 1;
    }else if(r->value == key) return 0;
    else if(key < r->value) return insertNode(r->left,key);
    else{
        return insertNode(r->right,key);
    }
}
void showTree(Root &r){
    deque<Node*> dq;
    dq.push_back(r);
    while(!dq.empty()){
        int size = dq.size();
        while(size--){
            Node* n = dq.front();
            cout << n->value << "   ";
            dq.pop_front();
            if(n->left != nullptr)
                dq.push_back(n->left);
            if(n->right != nullptr)
                dq.push_back(n->right);
        }
        cout << endl;
    }
}
int main()
{
    insertNode(r,45);
    insertNode(r,24);
    insertNode(r,53);
    insertNode(r,12);
    showTree(r);
    return	0;
}