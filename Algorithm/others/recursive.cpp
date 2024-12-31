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

void bfs(Node* node){
    deque<Node*> dq;
    dq.push_back(node);
    while(!dq.empty()){
        int size = dq.size();
        deque<Node*> dq2;
        while(size--){
            Node* tmp = dq.back();
            for(adjcent node of tmp){
                dq2.push_back(adj_node);
            }
            cout << dq.back().val;
            dq.pop_back();
        }
        for(int = 0; i < dq2.size(); i++){
            dq.push_back(dq2.back());
            dq2.pop_back();
        }
    }
}

int main()
{
    
    return	0;
}