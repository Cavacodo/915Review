#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    int* b; //int 型指针变量，存放的是int类型变量的地址
    a = 5;
    b = &a; //取地址符号，取出对应的地址
    cout << "a == " << a << endl;
    cout << "b == " << b << endl;
    cout << "&a == " << &a << endl;
    cout << "*b == " << *b << endl;
    return	0;
}