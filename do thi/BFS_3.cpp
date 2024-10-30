#include <bits/stdc++.h>
using namespace std;
long long n,m,u,v,d,tam,cx[1000001],buoc[1000001],i,j,truoc[1000001];
vector <long long>a[1000001];
queue <long long> q;
void bfs(long long u) {
    cx[u] = 1;
    buoc[u] = 0;
    q.push(u);
    int j;
    while(!q.empty()) {
        tam = q.front();
        q.pop();
        for(j=0;j<a[tam].size();j++) {
            if(cx[a[tam][j]] == 0) {
                cx[a[tam][j]] = 1;
                truoc[a[tam][j]] = u;
                buoc[a[tam][j]] = buoc[tam]+1;
                q.push(a[tam][j]);
            }
        }
    }
}
int main()
{
    ifstream fin("BFS_3.inp");
    ofstream fout("BFS_3.out");
    fin>>n>>m;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    for(i=1;i<=n;i++) {
        if(cx[i] == 0) {
            d++;
            bfs(i);
        }
    }
    fout<<d;
}
