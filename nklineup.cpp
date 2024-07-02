#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000001],ITmax[1000001],mx,mn,x,y,n,q,ITmin[1000001],i;
void build(ll node, ll left, ll right)
{
    int mid;
    if(left == right) ITmax[node] = ITmin[node]=a[left];
    else {
        mid = (left+right)/2;
        build(node*2,left,mid);
        build(node*2+1,mid+1,right);
        ITmax[node] = max(ITmax[node*2],ITmax[node*2+1]);
        ITmin[node] = min(ITmin[node*2],ITmin[node*2+1]);
    }
}
void query(ll node, ll left, ll right,ll i , ll j)
{
    ll mid;
    if(right<i || j<left) return ;
    if(i<=left && right<=j) {
       mx = max(mx,ITmax[node]);
       mn = min(mn,ITmin[node]);
    }
    else
    {
        mid = (left+right)/2;
        query(node*2,left,mid,i,j);
        query(node*2+1,mid+1,right,i,j);
    }
}
int main()
{
    cin>>n>>q;
    for(i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for(i=1;i<=q;i++){
        cin>>x>>y;
        mx = 0;
        mn = 1e7;
        query(1,1,n,x,y);
        cout<<mx-mn<<endl;
    }
}
