#include <bits/stdc++.h>
using namespace std;

long long n, m, a[1000006], b[1000006], dau, cuoi, giua, i, j, ps[1000006], mp[1000006],tam;

int main() {
    ifstream fin("khkt.inp");
    ofstream fout("khkt.out");

    fin >> n;
    for (i = 1; i <= n; i++) {
        fin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }

    fin >> m;
    for (i = 1; i <= m; i++) {
        fin >> b[i];
        dau = 1;
        cuoi = n;
        while(dau<=cuoi) {
            giua = dau+(cuoi-dau)/2;
            if(ps[giua] >= b[i]) {
                cuoi = giua - 1;
            } else dau = giua+1;
        }
        mp[giua]++;
        j = max(j,mp[giua]);
    }
    for(i=1;i<=n;i++) {
        if(mp[i] == j) fout<<i<<" ";
    }
    return 0;
}

/*
*/
