#include <bits/stdc++.h>
using namespace std;
long long n,k,m,u,v,cx[1000006],d,i;
vector<long long> a[1000006];
queue <long long> q;
void bfs(long long u) {
    cx[u] = 1;
    d = 0;
    int j,t,v1;
    q.push(u);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for(j=0;j<a[t].size();j++) {
            v1 = a[t][j];
            if(!cx[v1]) {
                cx[v1] = 1;
                d++;
                q.push(v1);
            }
        }
    }
}
int main()
{
    ifstream fin("ketban.inp");
    ofstream fout("ketban.out");
    fin>>n>>k>>m;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    bfs(k);
    fout<<d;
}
