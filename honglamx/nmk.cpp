#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef int bignum[50];
ll j,n,t,m,i,k;
bignum f[122][122][121];
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
void tinh(int i, int c,int du)
{
    if(i>n)
    {
        f[i][c][du][0] = 1;
        f[i][c][du][1] = (c==m && du == 0);
        return ;
    }
    if (f[i][c][du][0] != 0) return;
    f[i][c][du][0] = 1;
    for(int v = 0; v<= 9 ; v ++)
        if(c+v<=m){
        ll ndu = (du*10+v)%k;
        tinh(i+1,c+v,ndu);
        cong(f[i][c][du],f[i+1][c+v][ndu],f[i][c][du]);
    }
}
int main()
{
   // ifstream fin("nm.inp");
    //ofstream fout("nm.out");
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        memset(f,0,sizeof(f));
    //    for(i=1;i<=n;i++)
      //      for(j=1;j<=m;j++)
        tinh(1 , 0 ,0);

        for(i = f[1][0][0][0]; i>=1;i--) cout<<f[1][0][0][i];
       // cout<<f[1][0][0][0];
        cout<<endl;
    }
}

