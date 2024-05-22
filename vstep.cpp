#include <bits/stdc++.h>
using namespace std;
#define ll long long
unsigned ll f2[100005],f[100005],i,j,k,n,x;
int main()
{
    ios_base::sync_with_stdio();
   // freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin.tie();
    cout.tie();
    cin>>n>>k;
    for(i=1;i<=k;i++) {
            cin>>x;
        f[x] = -1;
    }
    f[1] = 1;
    f[0] = 0;
    for(i=2;i<=n;i++)
       if(f[i]==-1) {
        f[i] = 0;
       }else
        f[i] = (f[i-1]+f[i-2])%14062008;

       cout<<f[n];
}

