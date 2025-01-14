#include <bits/stdc++.h>
using namespace std;

long long n,k,m,i,s,j,mx,tam,d,a[1000006];

int main()
{
    ifstream fin("camdien.inp");
    ofstream fout("camdien.out");
    fin>>n>>k;
    for(i=1;i<=n;i++) {
        fin>>a[i];
        mx = max(mx,a[i]);
    }
  //  if(mx < n) {fout<<-1; return 0;}
    sort(a+1,a+n+1, greater<int>());
    s = a[1];
    d++;
    for(i=2;i<=n;i++)
    {
        tam = a[i];

        if(s < k)
        {
            s = s-1+tam;
            d++;
        }
    }
    if(s<k) fout<<-1;
    else
    fout<<d;
}
