#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,i,d,a[110],k;
string s;
typedef int bignum[105];
bignum f[105][105];
void cong(bignum a,bignum b, bignum c) {
    bignum t;
    memset(t,0,sizeof(t));
    ll i,nho;
    t[0] = max(a[0],b[0]);
    nho = 0;
    for(i=1;i<=t[0];i++) {
        nho = nho + a[i] + b[i];
        t[i] = nho%10;
        nho/=10;
    }
    if(nho>0) {
        t[0]++;
        t[t[0]] = nho;
    }
    c[0] = t[0];
    for(i=1;i<=t[0];i++) c[i] = t[i];
}
void tinh(ll i, ll c)
{
   if(i>n)
   {
       f[i][c][0] = 1;
       f[i][c][1] = (c==0);
       return ;
   }
   if(f[i][c][0] > 0) return;
   f[i][c][0] = 1;
   for(int v = 0 ; v<=1;v++)
    {
        if(v==0 || (v==1 && a[i] == 0)) {
        int c1 = c;
        if(v==0) {
            c1++;}
        else {c1--;}
        if(c1>=0) {
            tinh(i+1,c1);
            cong(f[i][c],f[i+1][c1],f[i][c]);
        }
    }
    }
}
int main()
{
    while(cin>>n) {
        cin>>s;
        k = 0;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(i=0;i<s.size();i++) {
            if(s[i] == '{' || s[i] == ' ') continue;
            if(s[i] == '}' || s[i] == ',') {
                a[k] = 1;
                k = 0;
            } else k=k*10+(s[i]-'0');
        }
        tinh(1,0);
        if(f[1][0][0] > 10) {
        for(i = f[1][0][0]; i>=f[1][0][0]-4;i--) cout<<f[1][0][i];
        cout<<"...";
        for(i = 5; i>=1;i--) cout<<f[1][0][i];
    } else
        for(i = f[1][0][0]; i>=1;i--) cout<<f[1][0][i];
        cout<<endl;
    }
}
