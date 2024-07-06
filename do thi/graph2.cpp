#include <bits/stdc++.h>
using namespace std;
//#define ll long long
vector<long long>a[10001];
long long n,m,i,u,v,d2,chuaxet[10001],d,dmax;
void dfs(long long u)
{
    long long j;
    chuaxet[u] = 0;
    for(j=0;j<a[u].size();j++) {
        if(chuaxet[a[u].at(j)] == 1)
            dfs(a[u].at(j));
    }
}
int main()
{
    ifstream fin("test.inp");
    fin>>n>>m;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(i=1;i<=n;i++) {
            chuaxet[i] = 1;
            a[i].push_back(i);
    }
    for(i=1;i<=n;i++){
        if(chuaxet[i]) {
                dfs(i);
                d2++;
        }
    }
    for(i=1;i<=n;i++) {
        d = a[i].size();
        dmax = max(dmax,d);
    }
    cout<<d2<<" "<<dmax;
    return 0;
}
