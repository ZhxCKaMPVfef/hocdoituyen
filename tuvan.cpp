#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000006],i,j,s,d,kq,res,dau,cuoi,giua;
int main()
{
    ifstream fin("tuvan.inp");
    ofstream fout("tuvan.out");
    fin>>n>>m;
    for(i=1;i<=n;i++) {fin>>a[i];}
    dau = 1;
    cuoi = 1e6;
    while(dau<=cuoi) {
        giua = dau+(cuoi-dau)/2;
        for(i=1;i<=n;i++)
            if(s<=m)
                s = s + (giua % a[i]);
        if(s<m) dau = giua+1;
        else {
            kq = giua;
            cuoi = giua-1;
        }
    }
    cout<<kq;
}
