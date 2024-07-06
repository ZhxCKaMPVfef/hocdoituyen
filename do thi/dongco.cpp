#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll chuaxet[100001],n,m,u,v,i,j;
ll d;
vector <ll> a[30001];
void dfs(int u)
{
    int j;
    d++;
    chuaxet[u] = 0;
    for(j=0;j<=a[u].size()-1;j++){
        if(chuaxet[a[u].at(j)]) dfs(a[u].at(j));
    }
}
int main()
{
    ifstream fin("dongco.inp");
    ofstream fout("dongco.out");
    fin>>n>>m;
    for(i=1;i<=n;i++) chuaxet[i] = 1;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    fout<<n-d<<endl;
    for(i=1;i<=n;i++)
    {
        if(chuaxet[i] == 1) fout<<i<<" ";
    }
}
