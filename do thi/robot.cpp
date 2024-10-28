#include <bits/stdc++.h>
using namespace std;
long long m,n,i,j,cx[1001][1001],s,d,buoc[1001][1001],a[1001][1001],tam,x,y,xx,yy,smax,dau,giua,cuoi,kq;
int vx[4] = {0,-1,0,1};
int vy[4] = {-1,0,1,0};
queue <long long> qx,qy;
bool bfs(long long u, long long v, long long t) {
    cx[u][v] = 1;
    //buoc[u][v] = a[u][v];
    qx.push(u);
    qy.push(v);
    while(!qx.empty()) {
        x = qx.front();
        y = qy.front();
        qy.pop();
        qx.pop();
        for(int k = 0;k<=3;k++) {
            xx = x+vx[k];
            yy = y+vy[k];
            if(xx > 0 && xx <= m && yy > 0&& yy<=n&& cx[xx][yy] == 0 && abs(a[xx][yy] - a[x][y]) <= t) {
                cx[xx][yy] = 1;
                qx.push(xx);
                qy.push(yy);
            }
        }
    } return cx[m][n];
}
int main()
{
    ifstream fin("test.inp");
    fin>>m>>n;
    for(i = 1 ; i<=m;i++)
        for(j=1;j<=n;j++)
            fin>>a[i][j];
    dau = 0;
    cuoi = 1e6;
    while(dau<=cuoi) {
        giua = dau + (cuoi-dau)/2;
        memset(cx,0,sizeof(cx));
        if(bfs(1,1,giua)) {kq = giua;cuoi = giua-1;}
        else {

            dau = giua+1;
        }
    }
    cout<<kq;
}
