//https://www.urionlinejudge.com.br/judge/pt/problems/view/2390
//URI 2390 - Escada Rolante
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int v[n], tot = 10;
    for(int i = 0; i < n ; ++i) {
        scanf("%d", &v[i]);
        if(i == 0) continue;
        else if(v[i]-v[i-1] < 10) tot += 10 - (10-(v[i]-v[i-1]));
        else tot+=10;
    }
    
    printf("%d\n", tot);
    return 0;
}