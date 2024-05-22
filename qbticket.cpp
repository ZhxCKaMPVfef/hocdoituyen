#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,i,j,a[10005],f[10005];
ll l1,l2,l3,c1,c2,c3,s,f1,v,tam;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin>>l1>>l2>>l3>>c1>>c2>>c3>>n>>s>>f1;
    for(i=1;i<=n;i++) cin>>f[i];
    for(i=1;i<=n;i++){
              if(a[i]-a[i-1]<l1) v = c1;
        else if(a[i]-a[i-1]<l2) v = c2;
        else v = c3;
        f[i] = abs(a[i-1]-a[i])+v;
        for(j=1;j<=n;j++){
            if(a[i]-a[j]<l1) v = c1;
        else if(a[i]-a[j]<l2) v = c2;
        else v = c3;
            f[i]= min(f[i],f[j]+f[i-j]+v);
    }
    }
    //cout<<f[f1];
    for(i=1;i<=n;i++) cout<<f[i]<<" ";
}
