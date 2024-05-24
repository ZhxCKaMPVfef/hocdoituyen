#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,s,j,a[5005][5005],f[5005][5005];
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    //freopen("test.inp","r",stdin);
   //freopen("test.out","w",stdout);
    cin>>m>>n;
    for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)cin>>a[i][j];
    for(i=1;i<=m;i++) f[i][1] = a[i][1];
    for(j=2;j<=n;j++)
    for(i=1;i<=n;i++) {
        f[i][j] = f[i][j-1];
        if(i>1) f[i][j] = max(f[i][j],f[i-1][j-1]);
        if(i<m) f[i][j] = max(f[i][j],f[i+1][j-1]);
        f[i][j] = f[i][j]+a[i][j];
    }
    ll x = 1;
    for(i=1;i<=m;i++){
        if(f[x][n]<f[i][n]) x=i;
    }
    cout<<f[x][n];
}
