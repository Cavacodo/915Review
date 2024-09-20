#include <bits/stdc++.h>
using namespace std;



int main()
{
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            for(int m = 0; m <= 9; m++){
                for(int n = 0; n <= 9; n++){
                    int n1,n2;
                    n1 = i*1000 + j*100 + m*10 + n;
                    n2 = m*1000 + i*100 + j*10 + n;
                    if(n1 + n2 == 7856){
                        cout << i << j << m << n << endl;
                    } 
                }
            }
        }
    }
    return	0;
}