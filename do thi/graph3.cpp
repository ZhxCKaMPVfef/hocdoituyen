#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1001][1001],t,x,y,chuaxet[100001],u,v,d,j,n,m,i,save[1001];
bool checkpoint;
void dfs(int u) {
    int j;
    chuaxet[u] = d;
    for(j=1;j<=n;j++)
        if(a[u][j]==1 && chuaxet[j] == 0) {
            dfs(j);
    }
}
int main()
{
    ifstream fin("test.inp");
    fin>>n>>m>>t;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u][v] = a[v][u] = 1;
    }
    for(i=1;i<=n;i++){
        if(chuaxet[i] == 0 ) {
            d++;
            dfs(i);
        }
    }
   // cout<<d<<endl;
    for(i=1;i<=t;i++) {
        fin>>x>>y;
        if(chuaxet[x] == chuaxet[y]) cout<<1<<endl;
        else cout<<0<<endl;
    }
}

