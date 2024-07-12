#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,t,x,i,k,f[55][55],a[100], d,tam, res,test;
ll tinh(ll i , ll dem) {
    if(i>50) return (dem==d);
    if(f[i][dem] !=  -1) return f[i][dem];
    ll cnt = 0;
    for(int v = 0; v<=1;v++) {
        if(dem+v <= d) cnt+=tinh(i+1,dem+v);
    }
    f[i][dem] = cnt;
    return cnt;
}
void truyvet1(ll i, ll dem)
{
    if(i>50) return;
    for(int v = 0 ; v <= a[i] ; v ++)
        if(dem+v<=d ){
        if(v<a[i]) t=t+tinh(i+1,dem+v);
        else truyvet1(i+1,dem+v);
    }
    //if(a[i] == 1) t+=tinh(i+1,dem);
    //else truyvet1(i+1,dem+a[i]);
}
void truyvet2 (ll i , ll dem)
{
    if(i>50) return ;
    for(int v = 0 ; v <= 1; v++)
        if(dem+v<=d){
        if(tinh(i+1,dem+v) < t) t-=tinh(i+1,dem+v);
        else
        {
            res = res * 2 + v;
            truyvet2(i+1,dem+v);
            break;
        }
    }
}
int main()
{
    //ifstream fin("test.inp");
    //ofstream fout("test.out");
    cin>>test;
    while(test--) {
        cin>>x>>k;
        tam = x;
        d = 0;
        for(i=50;i>=1;i--) {
            a[i] = tam%2;
            tam/=2;
            d+=a[i];
        }
      //  cout<<d<<endl;
        memset(f,-1,sizeof(f));
        //d=1;
        tinh(1,0);
        t = 1;
        truyvet1(1,0);
        //cout<<t<<endl;
        res = 0;
        t=t+k;
        if(t>f[1][0]) cout<<-1<<endl;
        else
        {
            truyvet2(1,0);
            if(res > 1e15) cout<<-1<<endl;
            else cout<<res<<endl;
        }
    }
}
