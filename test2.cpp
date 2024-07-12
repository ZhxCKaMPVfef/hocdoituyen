#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll x[100001],n,s,d;
void ngoac(int i)
{
    int j;
    for(int j=0;j<=1;j++){
        if(j==0) s++;
        else s--;
        if(s>=0)
        {
            x[i] = j;
            if(i<2*n) ngoac(i+1);
            else
                if(s==0){
                    d++;
                for(int k = 1;k<=2*n;k++)
                    if(x[k]==0) cout<<'(';
                   else cout<<')';
                               cout<<endl;

            }
        }
        if(j==0) s--; else s++;
    }
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
 //   freopen("ngoac.inp","r",stdin);
   // freopen("ngoac.out","w",stdout);
    cin>>n;
    ngoac(1);
    cout<<d;
}
