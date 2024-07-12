#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef int bignum[150];
ll j,n,t,m,a[1000001],i;
bignum f[122][122];
void cong(bignum a, bignum b, bignum c)
{
    bignum t;
    int nho,i;
    memset(t,0,sizeof(t));
    t[0] = max(a[0],b[0]);
    nho = 0;
    for(i=1;i<=t[0];i++) {
        nho = nho + a[i] + b[i];
        t[i] = nho%10;
        nho/=10;
    }
    if(nho>0) {
        t[0]++;
        t[t[0]] = nho;
    }
    c[0] = t[0];
    for(i=1;i<=t[0];i++) c[i] = t[i];
}
void tinh(int i, int c)
{
    if(i>n)
    {
        f[i][c][0] = 1;
        f[i][c][1] = (c==m);
        return ;
    }
    if (f[i][c][0] != 0) return;
    f[i][c][0] = 1;
    for(int v = 0; v<= 9 ; v ++)
        if(c+v<=m){
        tinh(i+1,c+v);
        cong(f[i][c],f[i+1][c+v],f[i][c]);
    }
}
int main()
{
   // ifstream fin("nm.inp");
    //ofstream fout("nm.out");
    cin>>t;
    while(t--) {
        cin>>n>>m;
        memset(f,0,sizeof(f));
                tinh(1,0);
        for(i = f[1][0][0]; i>=1;i--) cout<<f[1][0][i];
        cout<<endl;
    }
}

