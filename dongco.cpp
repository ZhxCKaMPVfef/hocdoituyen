#include <bits/stdc++.h>
using namespace std;
long long n,m,u,v,s,i,truoc[1000006],d,cx[1000006];
vector <long long> a[1000006];
void dfs(long long u)
{
    cx[u] = 1;
    vector <long long> ::iterator j;
    for(j=a[u].begin();j!=a[u].end();j++) {
        if(!cx[*j])
            dfs(*j);
    }
}
int main()
{
    ifstream fin("dongco.inp");
    ofstream fout("dongco.out");
    fin>>n>>m;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    for(i=1;i<=n;i++)
        if(!cx[i]) d++;
        fout<<d<<endl;
    for(i=1;i<=n;i++) if(!cx[i]) fout<<i<<" ";
}
