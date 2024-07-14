#include <bits/stdc++.h>
using namespace std;

string s;   //string 对象
string ss[10]; //string 数组

int main(){
    string s1("aaa");
    string s2(s1);
    string s3 = s1; 
    // 这三个的地址不一样
    // cout << &s1 << endl;
    // cout << &s2 << endl;
    // cout << &s3 <<endl;

    // 当使用string库中的字符串时，已经被重载了，所以可以直接使用==比较
    // 使用c风格时，如果直接使用 == 比较的是指向char数组的地址
    if(s1 == s3) cout << 1 << endl; // 在此处s1 == s2 == s3

    string s4(10,'c');  // 10个c
    string s5 = "jks";  //  可以使用这种方式进行java风格的创建字符串操作
    string s6 = string(10,'b'); // 10个b

    char cs[] = "abcedfg";
    // 注意此处因为传入的对象不同操作也不同
    string s7(cs,7);    // 复制cs数组前7个元素过来
    string s8(s6,4);    // 从s6的第4个元素开始复制
    string s9(s6,4,2);  // [4,4+2)的元素

    string s10 = s7.substr(2);  // substr 函数返回从2开始，到size的子字符串
    string s11 = s7.substr(2,3);    // substr(i,n)返回从i开始，长度为n的子字符串

    cout << s11[0] << endl; // 可以直接取出第i个位置的字符串，当char数组使用

    /*
        插入操作
    */

    string str = "to be question";
    string str2 = "the ";
    str.insert(6,str2); // 在第6个位置插入字符串

    /*
        替换操作
    */
    string str4 = "love you";
    // 注意这里不能使用str4.begin()作为开头
    str4.replace(0,4,"fuck");

    /*
        删除操作
    */

   string str3 = "This is an example sentence.";
   str3.erase(10,8);    // 删除第10个位置起的后面8个字符

   /*
        查找操作
   */
   
    string str5 = "abcdefa";
    cout << str5.find("defa") << endl;  //  输出3
    cout << str5.length() << endl;
    return 0;
}