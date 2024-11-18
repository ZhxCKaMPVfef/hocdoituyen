#include <bits/stdc++.h>
using namespace std;
long long i,j,n,m,u,v,cx[1000006],d;
vector <long long> a[1000006],a1[1000006];
stack <long long> s;
void dfs(long long u, int mode)
{
    cx[u] = 1;
    vector <long long>::iterator j;
    if(mode == 1) {
        for(j = a[u].begin(); j!=a[u].end(); j++)
            if(cx[*j] == 0) dfs(*j,1);
        s.push(u);
    }
    if(mode == 2) {
        for(j = a1[u].begin(); j!=a1[u].end(); j++)
            if(cx[*j] == 0) dfs(*j,2);
    }
}

int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a1[v].push_back(u);
    }
    for(i=1;i<=n;i++)
        if(cx[i] == 0 )
            dfs(i,1);
    long long t;
    for(i=1;i<=n;i++) cx[i] = 0;
    while(!s.empty()) {
        t = s.top();
        s.pop();
        if(cx[t] == 0) {
            d++;
            dfs(t,2);
        }
    }
    cout<<d;
}
