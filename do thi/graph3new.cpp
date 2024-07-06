
#include <bits/stdc++.h>
using namespace std;
//#define ll long long
vector<long long>a[10001];
long long n,m,i,u,v,chuaxet[10001],d,dmax,x,t,y;
bool checkpoint;
void dfs(long long u)
{
    long long j;
    chuaxet[u] = d;
    for(j=0;j<a[u].size();j++) {
        if(chuaxet[a[u].at(j)] == 0)
            dfs(a[u].at(j));
    }
}
int main()
{
    ifstream fin("test.inp");
    fin>>n>>m>>t;
    for(i=1;i<=m;i++) {
        fin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    //for(i=1;i<=n;i++) chuaxet[i] = 1;
    for(i=1;i<=n;i++){
        if(chuaxet[i]==0){
            d++;
            dfs(i);
        }
    }
    while(t--){
        fin>>x>>y;
        if(chuaxet[x] == chuaxet[y]) cout<<1<<endl;
        else cout<<0<<endl;
    }

//    cout<<a[x].at(y);
    return 0;
}
