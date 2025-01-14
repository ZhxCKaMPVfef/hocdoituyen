#include <bits/stdc++.h>
using namespace std;
long long n,mx,a[1000006],s[1000006],x,i,j,d;
bool cp = true;
int main()
{
    ifstream fin("chonggach.inp");
    ofstream fout("chonggach.out");
    fin>>n;
    for(i=1;i<=n;i++)

        fin>>a[i];

    sort(a+1,a+n+1);
    int k = 1;
    for(i=1;i<=n;i++)
    {
        if(k <= a[i]) k++;
    }
    fout<<k;
}
