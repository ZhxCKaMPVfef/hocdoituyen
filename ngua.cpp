#include <bits/stdc++.h>
using namespace std;
long long n,m,cx[1001][1001],x2,y2,x,y,xx,yy,k,xxx,yyy,buoc[1001][1001];
int vx[8] = {+1,-1,+2,+2,+1,-1,-2,-2};
int vy[8] = {-2,-2,-1,+1,+2,+2,+1,-1};
queue <long long> qx,qy;
void bfs(long long u , long long v) {
    qx.push(u);
    cx[u][v] = 1;
    qy.push(v);
    while(!qx.empty()) {
        x = qx.front();
        y = qy.front();
        qx.pop();
        qy.pop();
        for(k = 0 ;k <= 7;k ++) {
            xx = x+vx[k];
            yy = y+vy[k];
            if(xx <= m && xx > 0 && yy > 0 && yy <= m && !cx[xx][yy]) {
                buoc[xx][yy] = buoc[x][y]+1;
                cx[xx][yy] = 1;
                qx.push(xx);
                qy.push(yy);
            }
        }
    }
}
int main()
{
    cin>>m>>n>>xxx>>yyy>>x2>>y2;
    bfs(xxx,yyy);
    if(buoc[x2][y2] == 0) cout<<-1;
    else cout<<buoc[x2][y2];
}
