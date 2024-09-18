#include <bits/stdc++.h>
using namespace std;

int a, b;
char cal;

void SimCalculator()
{
    while (1)
    {
        cin >> a >> cal >> b;
        switch (cal)
        {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
            cout << a / b << endl;
            break;
        case '%':
            cout << a % b << endl;
            break;
        default:
            break;
        }
    }
}

int main()
{
    SimCalculator();
    return 0;
}