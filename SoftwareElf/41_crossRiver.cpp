// 一个非常巧妙的贪心问题，刚开始的时候以为只要保证让船回来的时候时间最短就好了，即让最小的那一个一直跟着船走，但并不是这样的。。
// 题解： 分两种过程，第一种就是上述过程，第二种情况是我们先让最快的跟次快的过河，然后让最快的回来，再让最慢的跟次慢的过河，再让次快的回来，这两种情况去较小的，前提是至少要有大于等于4个人，如果小于4个人的话，模拟就可以
// 还要注意奇数的情况 ，如果是奇数，那么最后会剩下3个人，即最快 次快 次次快，如果是偶数的话，由于我们每次减少两个，最后只剩下最快于次快

// 当n>=4时：
// (1+22+i)>=(i+i-1+21) 即 (2*2)>=(i+1) 时，可以用两种方法让最慢的两个过河。比较得出较快的那一个。
// 当n<=3时：
// 分情况讨论即可。


#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const int N=1010;
int a[N];

int main()
{
    int T;
    scanf("%d",&T);

    while(T--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }

        int sum=0;
        sort(a+1,a+n+1);

        if(n==1)
        {
            sum=a[1];
        }
        else if(n==2)
        {
            sum=a[2];
        }
        else if(n==3)
        {
            sum=a[1]+a[2]+a[3];
        }
        else
        {
            for(int i=n;i>1;i-=2)
            {
                if(i>=4)
                {
                    if(a[1]+a[i-1]>=2*a[2])
                        sum+=a[1]+a[i]+2*a[2];
                    else
                        sum+=2*a[1]+a[i]+a[i-1];
                }
                if(i==3)
                    sum+=a[1]+a[2]+a[3];
                if(i==2)
                    sum+=a[2];
            }
        }

        printf("%d\n",sum);

    }


    return 0;
}

