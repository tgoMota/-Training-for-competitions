//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=898
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll y, p, popes[100001];

int main(){
    while(scanf("%lld%lld", &y, &p) != EOF){
        for(ll i = 0; i < p ; ++i) scanf("%lld", &popes[i]);
        ll max = 1, ini, fim;
        for(ll i = 0; i < p ; ++i){
            ll cont = 0, j;
            for(j = i; popes[j] < popes[i] + y && j < p ; ++j) cont++;
            if(cont > max){
                max = cont;
                ini = i;
                fim = j-1LL;
            }
        }
        printf("%lld %lld %lld\n", max, popes[ini], popes[fim]);
    }

    return 0;
}