#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val('0'), left(nullptr), right(nullptr) {}
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void saveNode(string s,char val,TreeNode* head){
    TreeNode* tmp = head;
    for(int i = 0; i < s.size(); i++){
        char dir = s[i];
        if(dir == '0'){
            if(tmp->left != nullptr){
                tmp = tmp->left;
                continue;
            }
            else{
                tmp->left = new TreeNode();
                tmp = tmp->left;
            }

        }else{
            if(tmp->right != nullptr){
                tmp = tmp->right;
                continue;
            }
            else{
                tmp->right = new TreeNode();
                tmp = tmp->right;
            }
        }
    }
    tmp->val = val;
}

void getInfo(string s,TreeNode* head){
    TreeNode* tmp = head;
    for(int i = 0; i < s.size(); i++){
        if(tmp == nullptr){
            cout << "NaN" << endl;
            return ;
        }else{
            if(s[i] == '0'){
                if(tmp->left == nullptr){
                    cout << "NaN" << endl;
                    return ;
                }else{
                    tmp = tmp->left;
                }
            }else{
                if(tmp->right == nullptr){
                    cout << "NaN" << endl;
                    return ;
                }else{
                    tmp = tmp->right;
                }
            }
        }
    }
    cout << tmp->val << endl;
}

bool isPrefix(vector<string> s){
    sort(s.begin(),s.end(),[](const string s1,const string s2){
        return s1.size() < s2.size();
    });
    for(int i = 0; i < s.size(); i++){
        for(int j = s.size()-1; j > i; j--){
            int len = s[i].size();
            if(s[j].substr(0,len) == s[i]) return true;
            continue;
        }
    }
    return false;
}

int main()
{
    TreeNode* head = new TreeNode();
    saveNode("001",'A',head);
    saveNode("010",'B',head);
    getInfo("010",head);
    vector<string> v = {"001","010", "100","0001","0010"};
    cout << isPrefix(v) << endl;
    return	0;
}