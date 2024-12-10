#include <bits/stdc++.h>
using namespace std;
long long a[1001][1001], i , j , mi = LONG_MAX, xp , startpos , endpos , value,n,m,u,v,cx[1000006],nhan[1000006];
void dijkstra(long long u) {
    xp = u;
    cx[u] = 1;
    nhan[xp] = 0;
    while(xp != endpos) {
        cx[xp] = 1;
        for(j=1;j<=n;j++)
            if(a[xp][j] > 0 ) nhan[j] = min(nhan[j],nhan[xp] + a[xp][j]);
            mi = LONG_MAX;
        for(i=1;i<=n;i++) {
            if(mi > nhan[i] && cx[i] == 0) {
                xp = i;
                mi = nhan[i];
            }
        }
    }
}
int main()
{
    cin>>n>>m>>startpos>>endpos;
    for(i = 1 ; i <= m ; i++ ) {
        cin>>u>>v>>value;
        a[u][v] = a[v][u] = value;
    }
    for(i=1;i<=n;i++) nhan[i] = LONG_MAX;
    dijkstra(startpos);
    cout<<nhan[endpos];
}
