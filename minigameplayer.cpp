// NguyenHongLam
#include <bits/stdc++.h>
using namespace std;
long long n,i,x,collect,pos,a[1000006],total;
long long ipos = 0 , xvalue = 0;
bool ditruoc = false, player = false, npc = false;
void getvaluemax() {
    ipos = 0 , xvalue = 0;
    xvalue = a[1];
    for(i=1;i<=n;i++) {
        if(a[i] >= xvalue) {
            xvalue = a[i];
            ipos = i;
        }
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++){
      cin>>a[i];
      total+=a[i];
    }
    if(n%2==0){
        ditruoc = true;
        cout<<1<<endl;
    }
    else{
        ditruoc = false;
        cout<<0<<endl;
    }
    getvaluemax();
    while(total > 0) {
        //if(ditruoc) {
        if(total <= 0) break;
            cin>>ipos>>xvalue; // player 1;
            total -= xvalue;
            a[ipos] -= xvalue;
        //}
        for(i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
        cin>>pos>>collect;
        total -= collect;
        a[pos] -= collect;
        for(i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}

// 3 1 2 3
//10
//5 2 6 10 9 8 4 7 1 3
