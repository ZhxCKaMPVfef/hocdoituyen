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
    int tam = 0;
    getvaluemax();
    while(total > 0 || xvalue > 0) {

        cin>>pos>>collect;

        tam =  a[pos];
        a[pos]-= collect;
        total-=collect;
        if(a[pos] < 0){
            a[pos] = 0;
            total+=(collect - tam);
        }
        //break;
      for(i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
        getvaluemax();
        if(xvalue <= 0) break;
          cin>>pos>>collect;
        tam =  a[pos];
        a[pos]-= collect;
        total-=collect;
        if(a[pos] < 0){
            a[pos] = 0;
            total+=(collect - tam);
        }
        // 1 - 2 = -1
        // a - b = c
        //c+= b-a
        for(i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
        getvaluemax();
        if(xvalue <= 0) break;
    }
}

// 3 1 2 3
