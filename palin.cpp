#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,x[1000],i,f[50][101],lt[1000];

ll tinh(ll i , ll du)
{
   if(i>(n+1)/2) return du==0;
   if(f[i][du] != -1) return f[i][du];
   ll cnt = 0,ndu;
   for(int v = (i==1) ; v <= 9 ; v++) {
    ndu = (du+v*lt[n-i])%m;
    if(i!=n-i+1) ndu = (ndu+v*lt[i-1])%m;
    cnt+=tinh(i+1,ndu);
   }
   return f[i][du] = cnt;
}
void truyvet(ll i , ll du)
{
    if(i>(n+1)/2) return;
   ll ndu;
   for(int v = (i==1) ; v <= 9 ; v++) {
    ndu = (du+v*lt[n-i])%m;
    if(i!=n-i+1) ndu = (ndu+v*lt[i-1])%m;
        if(tinh(i+1,ndu)<k) k -=tinh(i+1,ndu);
        else
        {
            x[i] = x[n-i+1] = v;
            truyvet(i+1,ndu);
            break;
        }
   }
}
int main()
{
    cin>>n>>m>>k;
    lt[0] = 1;
    for(i=1;i<=n;i++) lt[i] = (lt[i-1]*10)%m;
    memset(f,-1,sizeof(f));
    cout<<tinh(1,0);
    cout<<endl;
    truyvet(1,0);
    for(i=1;i<=n;i++) cout<<x[i];
}


/*
     ll tam1 = pow1(10,n-i);
       dumoi = (du+v*tam1)%m;
        ll tam2 = pow1(10,i-1);
       if(i!=n-i+1){
        dumoi = (dumoi+v*tam2)%m;
       cnt+=tinh(i+1,dumoi);
       }
    }*/
