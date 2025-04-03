#include <bits/stdc++.h>
using namespace std;
long long n,m,u,v,s,i,truoc[1000006],d,buoc[1000006],cx[1000006],a1,b,c;
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
                truoc[v] = t;
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
        a[v].push_back(u);
        a[u].push_back(v);
    }
    bfs(a1);
    c = b;
    while(truoc[c] != 0)
    {
        d++;
        c = truoc[c];
    }
    if(d > 0)
    fout<<d-1;
    else fout<<-1;
}
