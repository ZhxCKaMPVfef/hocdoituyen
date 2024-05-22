#include<bits/stdc++.h>
using namespace std;
long long t[60001],r[60001],f[60001],n,k=1,i;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
     for(int i=1;i<=n-1;i++)
    {
        cin>>r[i];
    }
    f[1] = t[1];
    for( i=2;i<=n;i++)
    {
        f[i] = min(f[i-1]+t[i],f[i-2]+r[i-1]);
    }
    cout<<f[n];

}
