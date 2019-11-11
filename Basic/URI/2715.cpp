//https://www.urionlinejudge.com.br/judge/pt/problems/view/2715
//URI 2715 - Dividindo os Trabalhos I
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    int n, i;
    while(scanf("%d", &n) != EOF){
        vector<ll> v(n+1,0);
        for(i = 1; i <= n  ; ++i){
            scanf("%d", &v[i]);
            v[i]+=v[i-1];
        }
        ll minA = v[n]-v[1], dif;
        i = 1;
        while(i < n){
            dif = abs(v[n]-2*v[i]);
            minA = min(minA,dif);
            ++i;
        }
        printf("%lld\n", minA);
    }

    return 0;
}