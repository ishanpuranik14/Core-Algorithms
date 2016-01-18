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
#define pb push_back
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;

vvi matrices;
vvi dp;

int solve(int i, int j){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    else{
         int result=INF;
         for(int k=i;k<j;k++){
                 result=min(result, solve(i,k) + solve(k+1,j) + matrices[i][0]*matrices[k][1]*matrices[j][1]);
                 }
         dp[i][j]=result;
         return result;
         }
}

int main(){
    int n;
    cin>>n;
    vi t;
    t.resize(n,-1);
    dp.resize(n,t);              // dp is n X n
    for(int i=0;i<n;i++){
            int r,c;
            cin>>r>>c;
            vi temp;
            temp.pb(r);
            temp.pb(c);
            matrices.pb(temp);
            }
    cout<<solve(0,n-1)<<endl;
    int A;
    cin>>A;
    return 0;
}
