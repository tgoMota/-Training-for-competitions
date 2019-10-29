//https://www.urionlinejudge.com.br/judge/pt/problems/view/2388
//URI 2388 - Tacógrafo
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, v, t, d = 0;
    cin >> n;
    while(n--){
        cin >> t >> v;
        d += t*v;
    }
    printf("%d\n", d);

    return 0;
}