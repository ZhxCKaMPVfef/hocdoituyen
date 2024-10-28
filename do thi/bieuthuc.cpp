#include <bits/stdc++.h>
using namespace std;
long long n,a[1000006],i,j,tam,f[1000006],mx,s;
pair<long long,long long> pos;

int main()
{
    ifstream fin("bieuthuc.inp");
    fin>>n;
    for(i=1;i<=n;i++) {
        fin>>a[i];
        f[i]= f[i-1]+a[i];
    }
   for(i=1;i<=n-1;i++){
        s = max(s,f[i-1]+a[i]*a[i+1]+f[n]-f[i+1]);
   }
    cout<<s;
}
