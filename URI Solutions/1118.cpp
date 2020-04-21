//https://www.urionlinejudge.com.br/judge/pt/problems/view/1118
//URI 1118 - Várias Notas Com Validação
#include <bits/stdc++.h>
using namespace std;

int main(){

    double a, b, m;
    int t;
    do{
        while(cin >> a){
            if(a >= 0.00 && a <= 10.00) break;
            printf("nota invalida\n");
        }
        while(cin >> b){
            if(b >= 0.00 && b <= 10.00) break;
            printf("nota invalida\n");
        }
        printf("media = %.2lf\n", (a+b)/2.0);
        do{
            printf("novo calculo (1-sim 2-nao)\n");
        }while(cin >> t && (t != 1 && t != 2));
    }while(t == 1);

    return 0;
}