#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,i;
ll f[560][560];
int main()
{
    ifstream fin("acm.inp");
    fin>>n;
    for(i=1;i<=n;i++)
        for(int j = 1; j<=11;j++) fin>>f[i][j];
    for(i=1;i<=n;i++){
        for(int j = 1; j<=11;j++) cout<<f[i][j]<<" ";
    cout<<endl;
    }
}
