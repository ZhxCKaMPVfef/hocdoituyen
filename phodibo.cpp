#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,giua,r,tam,i,j,d,s,p,dau,cuoi,a[1000001],savepoint=0,b[1000001];
int main()
{
    ios_base::sync_with_stdio();
   ifstream fin("phodibo.inp");
   ofstream fout("phodibo.out");
    fin.tie();
    fout.tie();
    fin>>n>>r;
    for(i=1;i<=n;i++) fin>>a[i];
    for(i=1;i<=n;i++){
        dau = i;
        cuoi = n;
        tam=0;
        while(dau<=cuoi){
            giua = (dau+cuoi)/2;

            //cout<<"Debug 1: "<<a[i]<<" "<<a[giua]<<endl;
            if(a[giua]-a[i] > r) {
                //cout<<"Debug 2: "<<abs(a[i]-a[giua])<<endl;
           //cout<<"Debug 3: "<<" i: "<<i<<" "<<" giua: "<<giua<<" "<<"a[i] - a[giua] = "<<abs(a[i]-a[giua])<<endl;
            tam = giua;
                cuoi = giua-1;
            } else{
                dau = giua+1;
            }
        }
        if(tam>0)
        {
        savepoint=savepoint+(n-tam)+1;
        }


    }
    fout<<savepoint;
}
