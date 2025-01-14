#include <bits/stdc++.h>
using namespace std;
long long i,n,dau,cuoi,s;
pair<long long, long long>p[1000006];
int main()
{
    ifstream fin("cover.inp");
    ofstream fout("cover.out");

    cin>>n;
    for(i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+n+1);
    dau = p[1].first;
    cuoi = p[1].second;
    for(i=2;i<=n;i++)
    {
        if(p[i].first <= cuoi) cuoi = max(cuoi,p[i].second);
        else{
            s=s+cuoi-dau;
            dau = p[i].first;
            cuoi = p[i].second;
        }
    }
            s=s+cuoi-dau;
    cout<<s;
}
