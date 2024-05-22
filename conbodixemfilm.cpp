#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[5100][5100],i,j,c,n,w[5100];
int main()
{
    ios_base::sync_with_stdio();
    cin>>c>>n;
    for(i=1;i<=n;i++) cin>>w[i];
     for(i=1;i<=n;i++)
    for(j=1;j<=c;j++) {
        f[i][j]=f[i-1][j];
        if(j>=w[i]){
              if(f[i][j]<f[i-1][j-w[i]] + w[i])
        f[i][j]=f[i-1][j-w[i]] + w[i];
        }
    }
   cout<<f[n][c];
}
/*
    }*/
