#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,giua,r,tam,i,j,d,s,p,dau,cuoi,a,b,tung[1000001],truc[1000001];
pair<ll,ll> c[300005];

int main()
{
    ios_base::sync_with_stdio();
   ifstream fin("minroad.inp");
   ofstream fout("minroad.out");
    fin.tie();
    fout.tie();
    fin>>n>>a>>b;
    for(i=1;i<=n;i++) fin>>c[i].first>>c[i].second;
    sort(c+1,c+n+1);
    tung[0] = 0;
    truc[0] = 0;
    for(i=1;i<=n;i++){
        if(c[i].second == 1) {
            tung[i] = tung[i-1]+1;
            truc[i] = truc[i-1];
        }
        else {
            tung[i] = tung[i-1];
            truc[i] = truc[i-1]+1;
        }
    }
    ll savepoint = LONG_MAX;
    for(j=1;j<=n;j++){
        dau = 1;
        cuoi = j;
        i=-1;
        while(dau<=cuoi){
            giua = (dau+cuoi)/2;
            if(tung[j]-tung[giua-1]<a|| truc[j]-truc[giua-1]<b)
            cuoi = giua-1;
            else {
                i = giua;
                dau = giua+1;
            }
        }
        if(i!=-1) savepoint = min(savepoint,abs(c[j].first-c[i].first));
    }
    if(savepoint != LONG_MAX)
    fout<<savepoint;
    else fout<<-1;
}
