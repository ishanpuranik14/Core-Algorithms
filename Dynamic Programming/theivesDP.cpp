#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<iterator>
#include<sstream>
#define INF 100000000
#define MAX 100000
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;

LL dp[MAX];
int a[MAX];

ll recurse(int x){
               if(!x)return a[0];
               if(x<0)return 0;
               if(dp[x]!=-1)return dp[x];
               else{
                    ll m = max(a[x] + recurse(x-2), recurse(x-1));
                    dp[x]=m;
                    return m;
                    }
               }

int main(){
    int t,n;
    cin>>t;
    while(t--){
               cin>>n;
               for(int i=0;i<n;i++){
                       dp[i]=-1;
                       cin>>a[i];
                       }
               cout<<recurse(n-1)<<endl;
               // /*
               for(int i=0;i<n;i++){
                       cout<<dp[i]<<" ";
                       }
               cout<<endl;
               // */
               }
    int a;
    cin>>a;
    return 0;
}
