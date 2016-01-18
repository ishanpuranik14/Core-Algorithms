#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> c, m;
int min_count=10000000;

bool myfunction (int i,int j) { return (i>j); }

vector<int> change(int v){
    vector<int> ans;
    ans.resize(2,0);        
    if(!v){
           ans[1]=1;
           return ans;
           }
    if(m[v]!=-1){
                 ans[0]=m[v];
                 ans[1]=1;
                 return ans;
                 }
    else{
         int tmin=10000000;
         for(int i=0;i<c.size();i++){
                 if(c[i]<=v){
                             vector<int> temp;
                             temp=change(v-c[i]);
                             if(temp[1] && (1+temp[0])<tmin){
                                       tmin=1+temp[0];
                                       ans[0]=tmin;
                                       ans[1]=1;
                                       }
                             }
                 else{
                      break;
                      }
                 }
         if(ans[1]){
             m[v]=ans[0];
             }
         return ans;
         }
}

int main(){
    int v,n;
    cin>>v>>n;
    c.resize(n,0);
    m.resize(v+1,-1);
    for(int i=0;i<n;i++){
            cin>>c[i];
            }
    sort(c.begin(), c.end(), myfunction);
    vector<int> ans;
    ans=change(v);
    if(ans[1]){
               cout<<ans[0];
               }
    else{
         cout<<"not possible";
         }
    return 0;
}
