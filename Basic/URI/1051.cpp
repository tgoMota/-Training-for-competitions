//https://www.urionlinejudge.com.br/judge/pt/problems/view/1051
//URI 1051 - Imposto de Renda
#include <bits/stdc++.h>
using namespace std;

int main(){
    double d;
    cin >> d;
    if(d <= 2000) printf("Isento\n");
    else if(d <= 3000) printf("R$ %.2lf\n", 0.08*(d-2000.00));
    else if(d <= 4500) printf("R$ %.2lf\n", 0.08*(1000.00) + 0.18*(d-3000.00));
    else printf("R$ %.2lf\n", 0.08*1000.00 + 0.18 * 1500.00 + 0.28*(d-4500.00)); //0.028

    return 0;
}