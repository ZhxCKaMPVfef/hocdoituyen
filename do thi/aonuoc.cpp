#include <bits/stdc++.h>
using namespace std;
long long u,v,i,dem2,demmax,tam,j,d,n,m,k,a[1001][1001],cx[1001][1001];
int vx[4] = {0,-1,0,1};
int vy[4] = {-1,0,1,0};
queue <long long> qx,qy;
void bfs(long long u,long long v)
{
      cx[u][v] = 0;
    qx.push(u);
    qy.push(v);
    long long x,y,xx,yy;
    while(!qy.empty()) {
        x = qx.front();
        y = qy.front();
        qx.pop();
        qy.pop();
        for(k=0;k<=3;k++) {
            xx = x+vx[k];
            yy = y+vy[k];
            if(xx>0 && xx<=n && yy >0 && yy <= m && cx[xx][yy] == 1 && a[xx][yy] == 0 ) {
                d++;
                cx[xx][yy] = 0;
                a[xx][yy] = 1;
                qx.push(xx);
                qy.push(yy);
            }
        }
    }
}
int main()
{
    ifstream fin("aonuoc.inp");
    ofstream fout("aonuoc.out");
    fin>>n>>m;
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            fin>>a[i][j];
            cx[i][j]=1;
        }
    for(i=1;i<=n;i++)
    {
        if(a[i][1] == 0) a[i][1] = 1;
        if(a[1][i] == 0) a[1][i] = 1;
    }
     for(i=2;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i][j] == 0 && cx[i][j] == 1) {
                d = 1;
                bfs(i,j);
                dem2++;
                demmax = max(demmax,d);
            }
        }
    fout<<dem2<<endl<<demmax;
}
