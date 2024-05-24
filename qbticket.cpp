#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,i,j,a[1000005],f[1000005];
ll l1,l2,l3,c1,c2,c3,s,f1,v,tam;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
  //  freopen("test.inp","r",stdin);
  //  freopen("test.out","w",stdout);
    cin>>l1>>l2>>l3>>c1>>c2>>c3>>n>>s>>f1;
    for(i=2;i<=n;i++) cin>>a[i];
    if(s>f1) swap(s,f1);
    f[s] = 0;
    a[1] = 0;
    for(i=s+1;i<=f1;i++){

        f[i] = 1000000000000000;
        for(j=i-1;j>=s&&a[i]-a[j]<=l3;j--){
            //if(f[i]<f[j])
            if(a[i]-a[j]<l1) v = c1;
        else if(a[i]-a[j]<l2) v = c2;
        else v = c3;
            f[i] = min(f[i],f[j]+v);
        }
    }
    cout<<f[f1];
   // for(i=s;i<=f1;i++) cout<<f[i]<<" ";
}

/*   if(a[i]-a[i-1]<l1) v = c1;
        else if(a[i]-a[i-1]<l2) v = c2;
        else v = c3;
                    f[i] = v;
        for(j=1;j<=i;j++){
            if(a[i]-a[j]<l1) v = c1;
        else if(a[i]-a[j]<l2) v = c2;
        else v = c3;
            f[i]= min(f[i],f[j]+v);
    }*/
