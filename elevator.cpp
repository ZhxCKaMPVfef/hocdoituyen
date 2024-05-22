#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,i,s,j,a[10005],h[10005],c[10005],f[5005];
ll tam1,tam2,tam3,tam4,tam5,tam6,maxx;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
   // freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) {
            cin>>h[i]>>a[i]>>c[i];
        maxx = a[i];
        if(maxx<a[i]) maxx = a[i];
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++){
        if(a[i]>a[j]){
            tam1 = h[j];
            tam2 = a[j];
            tam3 = c[j];
            tam4 = h[i];
            tam5 = a[i];
            tam6 = c[i];
            h[i] = tam1;
            a[i] = tam2;
            c[i] = tam3;
            h[j] = tam4;
            a[j] = tam5;
            c[j] = tam6;
        }
    }
     for(i=1;i<=n;i++) {
        while(c[i]>0) {
            f[i] = f[i]+h[i];
            c[i]--;
            if(f[i]>a[i]){
                f[i]-=h[i];
                break;
            }
        }
        s+=f[i];
        if(s>maxx) s-=h[i];
    }
    cout<<s;
}
/*
   */
