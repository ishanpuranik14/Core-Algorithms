#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#include<iterator>
#include<set>
#include<sstream>
#define INF 100000000
#define MAX_N 1001
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

char a[MAX_N],b[MAX_N];
int dp[MAX_N][MAX_N];

int main(){
    int n=(int)strlen(gets(a));
    int m=(int)strlen(gets(b));
    for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                              if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
                              else{
                                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                                   }
                              }
            }
    cout<<dp[n][m];
    int A;
    cin>>A;
    return 0;
}
