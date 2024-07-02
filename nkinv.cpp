#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000001],it[1000001],mx,mn,x,y,n,q,ITmin[1000001],i;

int query(ll node, ll left, ll right,ll i , ll j)
{
    ll mid,s;
    if(right<i || j<left) return 0 ;
    if(i<=left && right<=j) return it[node];
    else
    {
        mid = (left+right)/2;
        s = query(node*2,left,mid,i,j) +
        query(node*2+1,mid+1,right,i,j);
    }
    return s;
}
void update(ll node, ll left, ll right , ll k) {
    ll mid;
    if(left == right) it[node]++;
    else
    {
        mid = (left + right ) / 2;
        if(k<=mid) update(2*node,left,mid,k);
        else update(2*node+1,mid+1,right,k);
        it[node] = it[2*node] + it[2*node+1];
    }
}
int main()
{
   // ifstream fin("test.inp");
    cin>>n;
    for(i=1;i<=n;i++) {
        cin>>x;
        y = y+query(1,1,60001,x+1,60001);
        update(1,1,60001,x);
    }
    cout<<y;
}
