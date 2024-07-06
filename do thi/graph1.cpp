
#include <bits/stdc++.h>
using namespace std;
//#define ll long long
vector<long long>a[10001];
long long n,m,i,u,v,chuaxet[10001],d,dmax,x;
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
    fin>>n>>m>>x;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(i=1;i<=n;i++) chuaxet[i] = 1;
    for(i=1;i<=n;i++){
        if(chuaxet[i]) dfs(i);
    }
    a[x].push_back(x);
    sort(a[x].begin(),a[x].end());
    for(i=0;i<a[x].size();i++) {
        cout<<a[x].at(i)<<" ";
    }
//    cout<<dmax;
    return 0;
}
