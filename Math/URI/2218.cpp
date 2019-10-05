//https://www.urionlinejudge.com.br/judge/pt/problems/view/2218
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, ans, t;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &t);
        ans = 1;
        for(int i = 1; i <= t ; ++i) ans+=i;
        printf("%d\n", ans);
    }

    return 0;
}