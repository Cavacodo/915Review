#include <bits/stdc++.h>
using namespace std;

int GCD(int a,int b){
    if(a < b) swap(a,b);
    while(b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return b == min(a,b) ? 1 : b;
}

int LCM(int a,int b){
    return a/(GCD(a,b)) * b;
}

void fraction_cal(string s){
    int len = s.size();
    string n1 , n2;
    string d1 , d2;
    int split1 = -1,split2 = -1,cal = -1;
    for(int i = 0; i < len; i++){
        if(s[i] == '/' && split1 == -1) split1 = i;
        else if(s[i] == '/' && split1 != -1) split2 = i;  
        else if(s[i] == '+' || s[i] == '-') cal = i;
    }
    n1 = s.substr(0,split1);
    d1 = s.substr(split1+1,cal-split1-1);
    n2 = s.substr(cal+1,split2-cal-1);
    d2 = s.substr(split2+1,len-1-split2);
    int in1 = stoi(n1), in2 = stoi(n2) , id1 = stoi(d1), id2 = stoi(d2);
    int lcm = LCM(id1,id2);
    in1 = lcm/id1 * in1;
    in2 = lcm/id2 * in2;
    if(s[cal] == '+'){
        int nn = in1 + in2;
        nn /= GCD(nn,lcm);
        lcm /= GCD(nn,lcm);
        cout << nn << "/" << lcm << endl;
    }else if(s[cal] == '-'){
        int nn = in1 - in2;
        nn /= GCD(nn,lcm);
        lcm /= GCD(nn,lcm);
        cout << nn << "/" << lcm << endl;
    }
}

int main()
{
    string s = "2/3+4/5";
    fraction_cal(s);
    return	0;
}