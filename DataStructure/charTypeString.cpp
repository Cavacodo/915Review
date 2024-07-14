#include <bits/stdc++.h>
using namespace std;

int my_strcmp(const char *s1, const char *s2);
int main()
{
    char str[] = {'f', 'u', 'c', 'k', ' ', 'u', '\0'};
    char str1[] = "fuck me";
    char str11[8] = "fuck me"; // 如果要添加长度初始化，我们需要至少8个长度
    char str2[50];
    strcpy(str2, str1);           // 复制str1内容到str2
    cout << strlen(str2) << endl; // 但是打印长度仍然是7
    char str3[] = " fuck it.";
    // strcat(str1,str3);  //   这样会报错，因为没有空闲空间了
    strcat(str2, str3); //  这样就没问题了

    char strc1[] = "loveu";
    char strc2[] = "loveu5";
    /*
        strcmp比较特殊
            str1 < str2 返回负数
            str1 == str2 返回0
            str1 > str2 返回正数
        按照字典序比，返回的是 *s1 - *s2，所以这里就是-53和53，表示大了
        简单的记住，就是前面一样的谁长谁大，前面不一样的谁先大谁大
    */
    cout << strcmp(strc1, strc2) << endl;
    cout << strcmp(strc2, strc1) << endl;
    /*
        strchr(s,c)函数用来返回第一次出现c的位置
        返回的是一个字符串，从开始出现的字符串
        要返回位置需要使用  strchr(strc1, 'l') - strc1
    */
    cout << strchr(strc1, 'l') - strc1 << endl;

    /*
        strstr函数
        好像是使用kmp实现的
        一样需要配合 strstr(st,st2) - st 使用才能返回下标
    */
    char st[] = "abcdef";
    char st2[] = "def";
    cout << strstr(st,st2) - st <<endl;
    return 0;
}

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
// TODO: Override strstr function