//https://www.urionlinejudge.com.br/judge/pt/problems/view/1087
//URI 1087 - Dama
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1, b1, a2, b2, ans;
    while(scanf("%d%d%d%d", &a1, &b1, &a2, &b2) && a1+b1+a2+b2 > 0){
        if(a1 == a2 && b1 == b2) ans = 0;
        else if(abs(a1 - a2) == abs(b1 - b2) || a1 == a2 || b1 == b2) ans = 1;
        else ans = 2;
        printf("%d\n", ans);
    }
    return 0;
}