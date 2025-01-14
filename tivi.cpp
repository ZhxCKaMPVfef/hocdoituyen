#include <bits/stdc++.h>
using namespace std;
long long n,i,j,s,d,tam,dau,cuoi,a[1000006],giua;
pair<long long , long long > p[1000006];
int main()
{
    ifstream fin("tivi.inp");
    ofstream fout("tivi.out");
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>p[i].first>>p[n+i].first;
        p[i].second = 2; // start
        p[i+n].second = 1; // end
    }
    sort(p+1,p+2*n+1);
    int res = 0;
    int dem = 0;
    for(i=1;i<=2*n;i++)
        if(p[i].second == 1) dem--;
        else {
            res = res+dem;
            dem++;
        }
    fout<<res;
}
