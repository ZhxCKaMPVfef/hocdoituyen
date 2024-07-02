#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,tam,i,j,d,a[1000001],s,k;
int tinh(int k)
{
    int i,hethan=0,days=1,dem2=0;
    for(i=1;i<=n;i++) {
        if(a[i]>=days) dem2++;
        else hethan++;
        if(dem2==k) {
            days++;
            dem2=0;
        }
    }
    return hethan;
}
int main()
{
    ios_base::sync_with_stdio();
   ifstream fin("milk.inp");
   ofstream fout("milk.out");
    fin>>n>>k;
    for(i=1;i<=n;i++) {
        fin>>a[i];
    }
    sort(a+1,a+n+1);
    fout<<tinh(k);
    fout<<endl;
    ll dau = 0;
    ll cuoi = n;
    ll vt,giua;
    while(dau<=cuoi){
        giua = (dau+cuoi)/2;
        if(tinh(giua)>0) dau=giua+1;
        else{
            vt = giua;
            cuoi=giua-1;
        }
    }
    fout<<vt;
}
