//https://www.urionlinejudge.com.br/judge/pt/problems/view/1171
//URI 1171 - Frequência de Números
#include <bits/stdc++.h>
using namespace std;
int v[2001];
int main(){
    int n, k, mx = 0;
    cin >> n;
    for(int i = 0; i < n ; ++i){
        cin >> k;
        v[k]++;
        mx = max(mx,k);
    }
    for(int i = 0; i <= mx ; ++i)
        if(v[i]) printf("%d aparece %d vez(es)\n", i, v[i]);

    return 0;
}