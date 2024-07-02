#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,tam,i,j,d,a[1000001],s,h;
ll tinh(int h){
    ll i , s=0;
    for(i=1;i<=n;i++){
        if(a[i]>h) s=s+a[i]-h;
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio();
    ifstream fin("philao.inp");
    ofstream fout("philao.out");
    fin.tie();
    fout.tie();
   // freopen("philao.inp","r",stdin);
    //freopen("philao.out","w",stdout);
    fin>>n>>m;
    for(i=1;i<=n;i++) {
        fin>>a[i];
    }
    ll dau=0;
    ll cuoi=1e6;
    ll giua = 0;
    h=a[1];
    for(i=2;i<=n;i++) {
        if(a[i]<h) h=a[i];
    }
    fout<<tinh(h);
    h = -1;
    while(dau<=cuoi){
        giua = (dau+cuoi)/2;
            if(tinh(giua)<m) cuoi = giua-1;
            else {
                h = giua;
                dau=giua+1;
            }
    }
    fout<<endl<<h;
}
