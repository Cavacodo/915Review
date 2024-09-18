// 找好数学关系
// TODO难算的一
// 重合的充要条件是任意一个矩阵的左下在另一个矩阵的右上角的左下
#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    double x, y;
    Pair(double x, double y) : x(x), y(y) {};
};

bool isIntersected(Pair *a1, Pair *a2, Pair *b1, Pair *b2)
{
    if (a1->x >= b2->x && a1->y >= b2->y && b1->x >= a2->x && b1->y >= a2->y)
        return true;
    return false;
}

double calArea(Pair *a, Pair *b)
{
    double x = abs(a->x - b->x);
    double y = abs(a->y - b->y);
    return x * y;
}

void AreaIntersection()
{
    setprecision(2);
    double ans = 0.0;
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    double right_1 = max(x1, x2), top_1 = max(y1, y2);
    double left_1 = min(x1, x2), bottom_1 = max(y1, y2);
    double right_2 = max(x3, x4), top_2 = max(y3, y4);
    double left_2 = min(x3, x4), bottom_2 = max(y3, y4);
    Pair *mxa = new Pair(right_1, top_1);
    Pair *mna = new Pair(left_1, bottom_1);
    Pair *mxb = new Pair(right_2, top_2);
    Pair *mnb = new Pair(left_2, bottom_2);
    if (!isIntersected(mxa, mna, mxb, mnb))
    {
        cout << ans << endl;
        return;
    }
    // a在右上
    if (mna->x <= mnb->x && mna->y <= mnb->y)
    {
        ans = calArea(mxb, mnb);
        cout << ans << endl;
        return;
    }
    else
    {
        // 部分包含
        double nx = max(mna->x, mnb->x);
        double ny = max(mna->y, mnb->y);
        Pair *n = new Pair(nx, ny);
        ans = calArea(mxb, n);
        cout << ans << endl;
        return;
    }
    // b在右上
    if (mnb->x <= mna->x && mnb->y <= mna->y)
    {
        ans = calArea(mxa, mna);
        cout << ans << endl;
        return;
    }
    else
    {
        // 部分包含
        double nx = max(mna->x, mnb->x);
        double ny = max(mna->y, mnb->y);
        Pair *n = new Pair(nx, ny);
        ans = calArea(mxa, n);
        cout << ans << endl;
        return;
    }
}

int main()
{
    AreaIntersection();
    return 0;
}