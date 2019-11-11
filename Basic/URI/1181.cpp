//https://www.urionlinejudge.com.br/judge/pt/problems/view/1181
//URI 1181 - Linha na Matriz
#include <bits/stdc++.h>
using namespace std;

int main(){

    char c;
    double ans = 0.0, k;
    int l;
    cin >> l;
    cin >> c;
    for(int i = 0 ; i < 12 ; ++i){
        for(int j = 0; j < 12 ; ++j){
            scanf("%lf", &k);
            if(i == l) ans+=k;
        }
    }
    if(c == 'S') printf("%.1lf\n", ans);
    else printf("%.1lf\n", ans/12.0);

    return 0;
}