#include<iostream>
using namespace std;

long long int fastExp(int p, int q){
     long long int res=1;
     if(q==1)return p;
     else if(!q)return 1;
     else{
          if(q%2==1){
                     res*=p;
                     res*=fastExp(p,q-1);
                     return res;
                     }
          else{
               res*=fastExp(p,q/2);
               res*=res;
               return res;
               }
          }
     }

int main(){
    int p,q;
    cin>>p>>q;
    long long int x = fastExp(p,q);
    cout<<x<<" ";
    cin>>p;
    return 0;
}
