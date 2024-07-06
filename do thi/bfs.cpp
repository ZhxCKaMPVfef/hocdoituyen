#include <bits/stdc++.h>
using namespace std;
#define ll long long
queue <int> q;
vector <int> a[10001];
ll cx[100001],buoc[100001],x,j,n,m,i,u,v,y;
void bfs(ll u) {
    int j,x;
    cx[u] = 0;
    buoc[u]=0;
    q.push(u);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(j=0;j<a[x].size();j++)
            if(cx[a[x].at(j)] == 1)
        {
            q.push(a[x].at(j));
            buoc[a[x].at(j)] = buoc[x]+1;
            cx[a[x].at(j)] = 0;
        }
    }
}
int main()
{
    ifstream fin("test.inp");
    fin>>n>>m>>x>>y;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(i=1;i<=n;i++) cx[i] = 1;
    bfs(x);
    if(buoc[y])
    cout<<buoc[y];
    else cout<<-1;
    //for(i=0;i<a[x].size();i++) cout<<a[x].at(i)<<" ";
}
