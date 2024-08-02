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
    while(total > 0 || xvalue > 0) {
        if(ditruoc){
            if(total%2==0){
                cout<<ipos<<" "<<xvalue<<endl;
                a[ipos] -=xvalue;
                total-=xvalue;
            }
            else
            {
                cout<<ipos<<" "<<xvalue/2<<endl;
                a[ipos] -=xvalue/2;
                total-=xvalue/2;
            }
        }
        cin>>pos>>collect;
        a[pos]-= collect;
        total-=collect;
        npc = true;
        player = false;
        //break;
  //     for(i=1;i<=n;i++) cout<<a[i]<<" ";
    //    cout<<endl;
        getvaluemax();
        if(xvalue <= 0) break;
        if(total%2 == 0) {
            cout<<ipos<<" "<<xvalue<<endl;
            total-=xvalue;
            a[ipos] -= xvalue;
        } else {
            if(xvalue/2 > 0){
                total = total - (xvalue/2);
                a[ipos] = a[ipos] - (xvalue/2);
                cout<<ipos<<" "<<xvalue/2<<endl;
            }
            else{
                cout<<ipos<<" "<<xvalue<<endl;
                total = total - (xvalue );
                a[ipos] = a[ipos] - (xvalue );
            }
        }
     //   for(i=1;i<=n;i++) cout<<a[i]<<" ";
      //  cout<<endl;
        getvaluemax();
        if(xvalue <= 0) break;
    }
}

// 3 1 2 3
