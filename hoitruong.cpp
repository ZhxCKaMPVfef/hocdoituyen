#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,tam1,tam2,tam3,tam4 ,i,j,p[10005],k[10005],f[10005];
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
  //  freopen("test.inp","r",stdin);
   // freopen("test.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) cin>>p[i]>>k[i];
    for(i=2;i<=n;i++)
        for(j=1;j<=i;j++)
        if(k[i]<k[j]) {
            tam3 = p[i];
            tam4 = k[i];
            tam1 = p[j];
            tam2 = k[j];
            p[i] = tam1;
            k[i] = tam2;
            p[j] = tam3;
            k[j] = tam4;
    }
     //for(i=1;i<=n-1;i++) cout<<p[i]<<" "<<k[i]<<endl;
    for(i=1;i<=n;i++){
            f[i] = abs(k[i]-p[i]);
        for(j=1;j<=n;j++)
                if(k[j]<=p[i]&&k[j]<=k[i])
        f[i] = max(f[i-1],f[j]+k[i]-p[i]);
       // cout<<f[i]<<endl;
    }
    cout<<f[n];
}
