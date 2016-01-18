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
#define MAX_N 100010
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

//SA O(nlog(n)).

char T[MAX_N]; // the input string, up to 100K characters
int n; // the length of input string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N]; // for counting/radix sort

void countingSort(int k) {
     int i, sum, maxi = max(300, n); // up to 255 ASCII chars or length of n
     memset(c, 0, sizeof c); // clear frequency table
     for (i = 0; i < n; i++) // count the frequency of each rank
         {c[i + k < n ? RA[i + k] : 0]++;}
     for (i = sum = 0; i < maxi; i++) {
         int t = c[i]; c[i] = sum; sum += t;
         }
         for (i = 0; i < n; i++) // shuffle the suffix array if necessary
             {tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];}
         for (i = 0; i < n; i++) // update the suffix array SA
         {SA[i] = tempSA[i];}
}

void constructSA() { // this version can go up to 100000 characters
     int i, k, r;
     for (i = 0; i < n; i++) RA[i] = T[i]-'.'; // initial rankings
     for (i = 0; i < n; i++) SA[i] = i; // initial SA: {0, 1, 2, ..., n-1}
     for (k = 1; k < n; k <<= 1) { // repeat sorting process log n times
     countingSort(k); // actually radix sort: sort based on the second item
     countingSort(0); // then (stable) sort based on the first item
     tempRA[SA[0]] = r = 0; // re-ranking; start from rank r = 0
     for (i = 1; i < n; i++) // compare adjacent suffixes
         {tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;}// if same pair => same rank r; otherwise, increase r
     for (i = 0; i < n; i++) // update the rank array RA
         {RA[i] = tempRA[i];}
     } }

// LCP (O(n))

int PHI[MAX_N], LCP[MAX_N], PLCP[MAX_N];

void computeLCP(){
     PHI[SA[0]]=-1;
     for(int i=1;i<n;i++){
             PHI[SA[i]]=SA[i-1];
             }
     //for(int i=0;i<n;i++)cout<<PHI[i]<<" ";
     //cout<<endl;
     for(int i=0,L=0;i<n;i++){
             if(PHI[i]==-1){
                           PLCP[i]=0;
                           continue;
                           }
             while(T[i+L]==T[PHI[i]+L])L++;
             PLCP[i]=L;
             L=max(L-1,0);
             }
     for(int i=0;i<n;i++){
             LCP[i]=PLCP[SA[i]];  
           }
     }    
     
int main() {
    // IMP : in main, append string with a '.' ; if '.' can be a part 
    //of string use something else and replace in sorting algo as well
    n = (int)strlen(gets(T));
    constructSA();
    for (int i = 0; i < n; i++) printf("%2d\t%s\n", SA[i], T + SA[i]);
    computeLCP();
    for(int i=0;i<n;i++)cout<<LCP[i]<<" ";
    cout<<endl;
    // Unique Substrings O(n)
    long total = n*(n-1);
    total/=2;            // total no of substrings
    
    for(int i=0;i<n;i++){
            if(LCP[i]){
                       if(LCP[i]==1)total--;
                       else{
                            total-=2;
                            }
                       }
            }
    cout<<total;
    int A;
    cin>>A;
    return 0;
}
