#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<iterator>
#define INF 100000000
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef long long ll;

#ifndef ONLINE_JUDGE
inline int getchar_unlocked()
{
    return getchar();
}
#endif

inline long long scn()
{
    long long n = 0, c = getchar_unlocked(),t=0;
    while(c < '0' || c > '9')
    {
        if(c==45)t=1;
        c = getchar_unlocked();
    }
    while(c >= '0' && c <= '9')n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();

    if(t==0)return n;
    else return -n;
}

int pow(int x, int n, int d) {
    ll r=x%d;
    if(!r)return 0;
    if(!n)return 1%d;
    ll p=1,s=1;
    ll k=(ll)log2(n) + 1;
    while(k--){
        int t=n&1;
        if(p==1){
            p*=r;
        }
        else{
            p*=p;
            p%=d;
        }
        if(t){
            s*=p;
            s%=d;
        }
        n=n>>1;
    }
    if(s<0)return s+d;
    return s;
}

int main(){
    int x,n,d;
    x=scn();
    n=scn();d=scn();
    cout<<pow(x,n,d);
    cin>>x;
    return 0;
}
