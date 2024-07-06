#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> a;
ll i,n,x,ma;
vector<ll>::iterator j;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>x;
        a.push_back(x);
    }
 //   cout<<ma;
    for(j=a.begin();j!=a.end();j++)
        cout<<*j<<" ";
}
