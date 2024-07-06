#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ld[4]={-1,0,1,0},a[1001][1001],j,n,m,u,d,dem,ma,v,i,cx[1001][1001];
ll lc[4]={0,-1,0,1};
void dfs(int u, int v)
{
    int dm,cm,j;
    d++;
    cx[u][v] = 0;
    for(j=0;j<=3;j++){
        dm = u+ld[j];
        cm = v+lc[j];
        if (a[dm][cm]==0 && cx[dm][cm]==1 &&dm > 0 &&dm <=m && cm>0&&cm<=n)
            dfs(dm,cm);
    }
}

int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {cin>>a[i][j];
         cx[i][j]=1;
        }
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==0 && cx[i][j]==1)
        {
                d=0;
                dfs(i,j);
                dem++;
                ma=max(ma,d);
        }
    cout<<dem<<endl<<ma;
}
