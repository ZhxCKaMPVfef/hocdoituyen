#include <bits/stdc++.h>
using namespace std;
long long n,m,s,t,d,u,v,cx[1000006],buoc[1000006],truoc[1000006],i,j;
vector<long long>a[1000006];
queue <long long> q;
ifstream fin("BFS_9.inp");
ofstream fout("BFS_9.out");
stack<long long> duongdi;

void bfs(long long u) {
    cx[u] = 1;
    buoc[u] = 1;
    q.push(u);

    while (!q.empty()) {
        long long t = q.front();
        q.pop();

        for (long long j = 0; j < a[t].size(); j++) {
            long long v = a[t][j];
            if (cx[v] == 0) {
                cx[v] = 1;
                truoc[v] = t;
                q.push(v);
            }
        }
    }

    if (truoc[t] == -1)
        fout << -1 << endl;
    else {
        long long x = t;
        while (x != -1) {
            duongdi.push(x);
            x = truoc[x];
        }

        fout << duongdi.size() << endl;
        while (!duongdi.empty()) {
            fout << duongdi.top() << " ";
            duongdi.pop();
        }
    }
}
int main()
{
    fin>>n>>m>>s>>t;
    truoc[t] = -1;
    truoc[s] = -1;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u].push_back(v);
    }
    bfs(s);
}
