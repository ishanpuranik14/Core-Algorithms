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
typedef vector<int> vi;

vi prime,primes;

void sieve(int n){
     prime.resize(n+1,true);
     prime[0]=prime[1]=false;
     for(int i=2;i<=n;i++){
                           if (prime[i]){
                                         primes.push_back(i);
                              if (i * 1ll * i <= n){
                                    for (int j=i*i; j<=n; j+=i){
                                        prime[j] = false;
                                         }
                                    }
                              }
                           }
     }
     
vi primeFactors(ll n){
                   vi factors;
                   //cout<<"entered 1"<<endl;
                   int pf_ind=0 , pf= 2;
                   while(n!=1 && (pf*pf)<=n ){
                              while(n%pf==0){
                                             //cout<<pf<<endl;
                                             n/=pf;
                                             factors.push_back(pf);
                                             }
                              pf=primes[++pf_ind];
                              }
                   //cout<<" finished 1";
                   if(n!=1)factors.push_back(n);
                   return factors;
               }
               
int main(){
    sieve(10000001);
    vi res=primeFactors(124421124);
    for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
          }
    int a;
    cin>>a;
    return 0;
}
