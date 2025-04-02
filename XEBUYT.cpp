#include <bits/stdc++.h>
using namespace std;
long long n,m,u,v,s,i,truoc[1000006],d,buoc[1000006],cx[1000006],a1,b;
vector <long long> a[1000006];
queue <long long> q;
void bfs(long long u) {
    cx[u] = 1;
    buoc[u] = 0;
    q.push(u);
    long long t,j;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for(j=0;j<a[t].size();j++) {
            long long v = a[t][j];
            if(!cx[v]) {
                cx[v] = 1;
                truoc[j] = t;
                buoc[v] = buoc[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    ifstream fin("xebuyt.inp");
    ofstream fout("xebuyt.out");
    fin>>n>>a1>>b;
    for(i=1;i<=n;i++) {
        fin>>u>>v;
        a[u].push_back(v);
    }
    for(i=a1;i<=b;i++) {
        truoc[b] = -1;
        if(!cx[i]) {
            bfs(i);
        }
        if(truoc[b] != 0) d++;
    }
    if(d > 0)
    fout<<d;
    else fout<<-1;
}
