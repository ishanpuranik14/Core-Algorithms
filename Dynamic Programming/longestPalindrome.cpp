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
#define MAX_N 100
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

bool dp[MAX_N][MAX_N];
char T[MAX_N];
int n;

// O(n^2)

int main(){
    n=(int)strlen(gets(T));
    if(n==1){
             cout<<1;
             int A;
             cin>>A;
             return 0;
             }
    for(int i=0;i<n;i++)dp[i][i]=true;
    for(int i=0;i<n-1;i++){
            if(T[i]==T[i+1])dp[i][i+1]=true;
            else{
                 dp[i][i+1]=false;
                 }
            }
    for(int l=3;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                    if(T[i]==T[i+l-1] && dp[i+1][i+l-2])dp[i][i+l-1]=true;
                    else{
                         dp[i][i+l-1]=false;
                         }
                    }
            }
    // find longest
    int maxi,maxj,max=1;
    for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                             if(dp[i][j] && (j-i+1)>max){
                                          max=j-i+1;
                                          maxi=i;
                                          maxj=j;
                                          }
                               }
            }
    cout<<max<<endl;
    cout<<maxi<<" "<<maxj;
    int A;
    cin>>A;
    return 0;
}
