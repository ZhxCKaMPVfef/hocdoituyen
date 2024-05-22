#include <bits/stdc++.h>
using namespace std;
#define ll long
 ll f[100001],s,i,j,k,n,a[100001];
int main()
{
    ios_base::sync_with_stdio();
 // freopen("test.inp","r",stdin);
//freopen("test.out","w",stdout);
    cin.tie();
    cout.tie();
    cin><k;
    for(i=1;i<=n;i++) cin>>a[i];
    f[1] = a[1];
    for(i=2;i<=n;i++) {
        f[i]=min(f[i-2],f[i-1])+a[i-1];
    }
    cout<<f[n];
}
