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
/*
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
}*/

int main(){
    ll n,tmx;
    cin>>n;
    ll s[n+1];
    s[0]=0;
    cin>>s[1];
    tmx=s[1];
    for(ll i=2;i<=n;i++){
            ll temp;
            cin>>temp;
            if(temp>tmx)tmx=temp;
            s[i]=s[i-1]+temp;
            }
    if(tmx<0){
              cout<<tmx;
              cin>>n;
              return 0;
              }
    ll md=0, mx=s[0], mn=s[0];
    for(int i=1;i<=n;i++){
            if(s[i]<mn){
                        mn=mx=s[i];
                         }
            else{
                 if(s[i]>mx){
                          mx=s[i];
                          md=max(md, mx-mn);
                      }
                 }
            }
    cout<<md;
    cin>>n;
    return 0;
}
