#include <bits/stdc++.h>
using namespace std;

// O(n^2) 超时
class Solution {
public:
    int isLetter(string s){
        if(s[0] <= 'z' && s[0] >= 'a') return 1;
        if(s[0] >= 'A' && s[0] <= 'Z') return 1;
        return 0;
    }
    vector<string> findLongestSubarray(vector<string>& array) {
        vector<string> ans;
        int l = -1,r = -1,len = 0;
        vector<int> letter(array.size()+1,0);
        vector<int> number(array.size()+1,0);
        for(int i = 1; i <= array.size(); i++){
            int t = isLetter(array[i-1]);
            letter[i] = letter[i-1] + t;
            number[i] = number[i-1] + !t;
        }
        for(int i = 1; i <= array.size(); i++){
            for(int j = 0; j < i; j++){
                if(letter[i] - letter[j] == number[i] - number[j] && i - j > len){
                    len = max(len,i-j);
                    l = j+1;
                    r = i;
                }
            }
        }
        if(l == -1 || r == -1) return ans;
        for(int i = l; i <= r; i++){
            ans.push_back(array[i-1]);
        }
        return ans;
    }
};


//好方法
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        // 最后返回是左开右闭
        unordered_map<int, int> vis{{0, -1}};
        int s = 0, mx = 0, k = 0;
        for (int i = 0; i < array.size(); ++i) {
            s += array[i][0] >= 'A' ? 1 : -1;
            if (vis.count(s)) {
                int j = vis[s];
                if (mx < i - j) {
                    mx = i - j;
                    k = j + 1;
                }
            } else {
                vis[s] = i;
            }
        }
        return vector<string>(array.begin() + k, array.begin() + k + mx);
    }
};

int main()
{
    Solution sol;
    vector<string> s = {"42","10","O","t","y","p","g","B","96","H","5","v","P","52","25","96","b","L","Y","z","d","52","3","v","71","J","A","0","v","51","E","k","H","96","21","W","59","I","V","s","59","w","X","33","29","H","32","51","f","i","58","56","66","90","F","10","93","53","85","28","78","d","67","81","T","K","S","l","L","Z","j","5","R","b","44","R","h","B","30","63","z","75","60","m","61","a","5","S","Z","D","2","A","W","k","84","44","96","96","y","M"};
    sol.findLongestSubarray(s);
    return	0;
}