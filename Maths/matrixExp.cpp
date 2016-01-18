#include<iostream>
#include<cstdio>
using namespace std;
#define MAX_N 30

struct Matrix{ int mat[MAX_N][MAX_N];int rows;int columns;};

Matrix matMul(Matrix a, Matrix b){
       Matrix c;
       for(int i=0;i<a.rows;i++){
               for(int j=0;j<b.columns;j++){
                       for(int k = c.mat[i][j] = 0; k<b.rows; k++){
                               c.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]);
                               c.mat[i][j]%=1000000007;
                               }
                      }
               }
       return c;
       }

Matrix matPow(Matrix base, int p) {
       Matrix ans;
       for (int i = 0; i < MAX_N; i++){
            for (int j = 0; j < MAX_N; j++){
                ans.mat[i][j] = (i == j);
                }
            }
       while (p) { 
             if (p & 1) ans = matMul(ans, base); 
             base = matMul(base, base);
             p >>= 1;
             }
             return ans;
       }

int main(){
    Matrix a;
    Matrix ans;
    int ro,c,n,m;
    cin>>n>>m;
    a.rows=n;
    cout<<" llll";
    a.columns=n;
    cout<<" llll";
    for(int i=0;i<n;i++){
            cout<<" llll";
    	for(int j=0;i<n;j++){
    		a.mat[i][j]=0;
    	}
     }
    cout<<"ffff";
    for(int i=0;i<m;i++){
            scanf("%d%d",&ro,&c);
            cout<<ro<<" " <<c<<"\n";
            a.mat[ro-1][c-1]=1;
            }
    for(int i=0;i<n;i++){
    	for(int j=0;i<n;j++){
    		printf("%d%s",&a.mat[i][j]," ");
    	}
    	cout<<"\n";
    }
    int ayu, gau;
    scanf("%d%d",&ayu,&gau);
    int l,r;
    scanf("%d%d",&l,&r);
    if(l==r){
             ans = matPow(a,l);
             for(int i=0;i<ans.rows;i++){
                     for(int j=0;j<ans.columns;j++){
                             printf("%d%s",&ans.mat[i][j]," ");
                           }
                     printf("%s","\n");
                     }
             printf("%d",ans.mat[ayu-1][gau-1]);
             }
    else{
         }
    return 0;
}
