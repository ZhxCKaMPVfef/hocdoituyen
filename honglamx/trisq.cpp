#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[20][20][20][20];
ll n,t,a[20],x[20],i;
ll tinh(int i , int mi1, int mi2,int mx)
{
    if(i>n)
        return 1;

    if(f[i][mi1][mi2][mx] != -1) return f[i][mi1][mi2][mx];
    ll cnt=0;
    int mxx,m1,m2;
    for(int v = 1; v<=n; v++) {
          mxx = max(mx,v);
         m1 = mi1;
         m2 = mi2;
        if(v<mi1) {
            m1 = v;
            m2 = mi1;
        } else
            if(v<mi2) m2 = v;
        if(m1+m2>mxx) {
            cnt=cnt+tinh(i+1,m1,m2,mxx);
    }
    }
    return f[i][mi1][mi2][mx] = cnt;
}
void truyvet1(int i , int mi1, int mi2,int mx)
{
    if(i>n) return ;
    for(int v = 1; v <= n; v++) {
        int m1,m2,mxx;
        mxx = max(mx,v);
         m1 = mi1;
         m2 = mi2;
        if(v<mi1) {
            m1 = v;
            m2 = mi1;
        } else
            if(v<mi2) m2 = v;
        if(m1+m2>mxx)  {
            if((tinh(i+1,m1,m2,mxx))<t)
                t = t - tinh(i+1,m1,m2,mxx);
            else {
                x[i]=v;
                truyvet1(i+1,m1,m2,mxx);
                break;
            }
        }
    }
}
void truyvet2(int i , int mi1, int mi2,int mx)
{
    if(i>n) return ;
    for(int v = 1;v<=a[i];v++) {
        int m1,m2,mxx;
       mxx = max(mx,v);
         m1 = mi1;
         m2 = mi2;
        if(v<mi1) {
            m1 = v;
            m2 = mi1;
        } else
            if(v<mi2) m2 = v;
        if(m1+m2>mxx){
            if(v<a[i]) t = t+tinh(i+1,m1,m2,mxx);
            else truyvet2(i+1,m1,m2,mxx);
        }
    }
}
int main()
{
    cin>>n>>t;
    memset(f,-1,sizeof(f));
    for(i=1;i<=n;i++) cin>>a[i];
    cout<<tinh(1,n+1,n+1,0)<<endl;
    truyvet1(1,n+1,n+1,0);
    for(i=1;i<=n;i++) cout<<x[i]<<" ";
    t = 1;
    cout<<endl;
    truyvet2(1,n+1,n+1,0);
    cout<<t<<endl;
}
