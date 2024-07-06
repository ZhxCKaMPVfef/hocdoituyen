#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll truoc[100001],i,cx[1000001],u,v,m,n,x,y;
vector <ll> a[100001];
queue <ll> q;
stack <ll> s;
void bfs(int u)
{
    int j,x;
    cx[u] = 0;
    truoc[u] = 0;
    q.push(u);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(j=0;j<=a[x].size()-1;j++)
        {
            if(cx[a[x].at(j)]) {
                 q.push(a[x].at(j));
            truoc[a[x].at(j)] = x;
            cx[a[x].at(j)] = 0;
            }
        }
    }
}
int main()
{
    cin>>n>>m>>x>>y;
    for(i=1;i<=n;i++) cx[i] = 1;
    for(i=1;i<=m;i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    bfs(x);
    s.push(y);
    while(truoc[y]!=0) {
        s.push(truoc[y]);
        y = truoc[y];
    }
   while(!s.empty())
    {
    cout<<s.top()<<" "; s.pop();
   }
}
