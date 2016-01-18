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

vector<int> a,b;
int main(){
    int n,ans=0;
    cin>>n;
    a.resize(n,0);
    b.resize(n,1);
    for(int i=0;i<n;i++){
            cin>>a[i];
            }
    for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                                if(a[j]<a[i]){
                                              b[i]=max(b[j]+1,b[i]);
                                              }
                                }
            ans=max(ans,b[i]);
            }
    //for(int i=0;i<n;i++)cout<<b[i]<<" ";
    cout<<ans;
    cin>>n;
    return 0;
}
