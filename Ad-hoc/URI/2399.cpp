//https://www.urionlinejudge.com.br/judge/pt/problems/view/2399
//URI 2399 - Campo Minado
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    scanf("%d", &n);
    int mines[n+2], ans[n+2];
    ans[0] = mines[0]= 0;
    ans[n+1] = mines[n+1] = 0;
    for(int i = 1; i <= n ; ++i) {
        scanf("%d", &mines[i]);
        ans[i] = 0;
    }
    for(int i = 1; i <= n ; ++i){
        if(mines[i-1]) ans[i]++;
        if(mines[i]) ans[i]++;
        if(mines[i+1]) ans[i]++;
    }

    for(int i = 1; i <= n ; ++i) printf("%d\n", ans[i]);

    return 0;
}