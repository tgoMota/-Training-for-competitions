#include <bits/stdc++.h>
using namespace std;

int t, m, moedas[101], memo[101][501*101];

// 1° Solucao
int pd(int dif, int ind){
    if(ind == 0) return abs(dif);
    int& ans = memo[ind][abs(dif)];
    if(ans != -1) return ans;
    return ans = min(pd(dif+moedas[ind], ind-1), pd(dif-moedas[ind], ind-1));
}

//2° Solucao - pd(0,0,m)
// int pd(int v1, int v2, int ind){
//     if(ind == 0) return abs(v1-v2);
//     int& ans = memo[ind][abs(v1-v2)];
//     if(ans != -1) return ans;
//     return ans = min(pd(v1 + moedas[ind],v2, ind-1), pd(v1, v2+moedas[ind], ind-1));
// }

int main(){
    cin >> t;
    while(t--){
        cin >> m;
        memset(memo, -1, sizeof(memo));
        for(int i = 1; i <= m ; ++i) cin >> moedas[i];
        printf("%d\n", pd(0,m));
    }

    return 0;
}
