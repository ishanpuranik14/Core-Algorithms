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

ll numPF(ll n){
               int pf_ind=0 , pf= 2;
               ll count=0;
               while(n!=1 && (pf*pf)<=n ){
                          while(n%pf==0){
                                         //cout<<pf<<endl;
                                         n/=pf;
                                         count++;
                                         }
                          pf=primes[++pf_ind];
                          }
               //cout<<" finished 1";
               if(n!=1)count++;
               return count;
            }
            
ll numDiffPF(ll n){
               int pf_ind=0 , pf= 2;
               ll count=0,flag=0;
               while(n!=1 && (pf*pf)<=n ){
                          if(n%pf==0){
                                      flag=pf;
                                      count++;
                                      }
                          while(n%pf==0){
                                         //cout<<pf<<endl;
                                         n/=pf;
                                         }
                          pf=primes[++pf_ind];
                          }
               //cout<<" finished 1";
               if(n!=1){
                        if(n!=flag)count++;
                        }
               return count;
               }
               
ll numDiv(ll n){
               int pf_ind=0 , pf= 2;
               ll div=1;
               while(n!=1 && (pf*pf)<=n ){
                          ll count=0;
                          while(n%pf==0){
                                         //cout<<pf<<endl;
                                         n/=pf;
                                         count++;
                                         }
                          div*=(count+1);
                          pf=primes[++pf_ind];
                          }
               //cout<<" finished 1";
               if(n!=1)div*=2;
               return div;
             }
             
ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
    while (N != 1 && (PF * PF <= N)) {
        ll power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
        }
    if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);
    return ans;
}

ll eulerPhi(ll n){                         //no of +ve ints that are coprime to n
               int pf_ind=0 , pf= 2;
               ll count=n;
               while(n!=1 && (pf*pf)<=n ){
                          if(n%pf==0)count-=(count/pf);
                          while(n%pf==0){
                                         //cout<<pf<<endl;
                                         n/=pf;
                                         }
                          pf=primes[++pf_ind];
                          }
               //cout<<" finished 1";
               if(n!=1)count-=(count/n);
               return count;
               }

int main(){
    sieve(10000001);
    
    return 0;
}
