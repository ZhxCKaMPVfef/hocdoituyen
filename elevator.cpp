#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct DATA{
    ll h,c,a;
} v[450];
ll k,i,j,x,f[400005];
bool sosanh(DATA x, DATA y){
    if(x.a < y.a) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin>>k;
    for(i=1;i<=k;i++) cin>>v[i].h>>v[i].a>>v[i].c;
    sort(v+1,v+k+1,sosanh);
    for(j=1;j<=40000;j++) f[j] = false;
    f[0] = true;
    ll jmax = 0;
    for(i=1;i<=k;i++)
        for(j=v[i].a;j>0;j--)
        for(x=1;x<=v[i].c&&x*v[i].h<=j;x++)
            f[j] = f[j]||f[j-x*v[i].h];
    for(i=1;i<=k;i++){
        for(j=v[i].a; j>0;j--) {
                if(f[j] == true){
                jmax = j;
                break;
                }
        }
    }
    cout<<jmax;
}
