#include <bits/stdc++.h>
using namespace std;
#define ll long
 ll f[100001],i,j,k,n,r[100001],t[100001];
int main()
{
    ios_base::sync_with_stdio();
 //  freopen("test.inp","r",stdin);
   // freopen("test.out","w",stdout);
    cin.tie();
    cout.tie();
    cin>>n;
    for(i=1;i<=n;i++) cin>>t[i];
    for(i=1;i<=n;i++) cin>>r[i];
    f[1]=t[1];
    for(i=2;i<=n;i++) f[i] = min(f[i-1]+t[i],f[i-2]+r[i-1]);
    cout<<f[n];
}

