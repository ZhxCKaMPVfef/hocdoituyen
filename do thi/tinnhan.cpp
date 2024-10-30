#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,u,v,cx[1000006],d,dmin=LONG_MAX;
vector<long long> a[1000006];
queue <long long> q;
void bfs(long long u) {
    cx[u] = 1;
    q.push(u);
    int j,t,v1;
    while(!q.empty()) {
        t = q.front();
        q.pop();
        for(j=0;j<a[t].size();j++) {
            v1 = a[t][j];
            if(!cx[v1]) {
                cx[v1] = 1;
                q.push(v1);
            }
        }
    }
}
int main()
{
    ifstream fin("tinnhan.inp");
    ofstream fout("tinnhan.out");
    fin>>n>>m;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    for(i=1;i<=n;i++) {
        if(!cx[i]) {
            d++;
            bfs(i);
        }
    }
    fout<<d;
}
