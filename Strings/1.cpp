#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    char ar[n];
    for(int i=0;i<n;i++){
            if(s[i]=='a')ar[i]='z';
            else{
                 ar[i]=s[i]-1;
                 }
            }
    for(int i=0;i<n;i++)cout<<ar[i];
    return 0;
}
