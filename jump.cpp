#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,giua,tam,i,j,d,s,p,dau,cuoi,b[1000001];
pair<ll,ll > a[100001];
int main()
{
    ios_base::sync_with_stdio();
   ifstream fin("jump.inp");
   ofstream fout("jump.out");
    fin>>n>>p;
    for(i=1;i<=n;i++){
        fin>>a[i].first;
        a[i].second = i;
    }
    sort(a+1,a+n+1);
    b[1] = a[1].second;
    for(i=2;i<=n;i++) b[i] = min(b[i-1],a[i].second);
    ll kq=0;
    for(j=2;j<=n;j++){
        dau = 1;
        cuoi = j-1;
        i = 0;
        while(dau<=cuoi) {
            giua = (dau+cuoi)/2;
            if(a[giua].first>a[j].first-p) cuoi=giua-1;
            else {
                i = giua;
                dau = giua+1;
            }
        }
        if(i>0) kq=max(kq,a[j].second-b[i]);
    }
    fout<<kq;
}
