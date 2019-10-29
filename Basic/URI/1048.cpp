//https://www.urionlinejudge.com.br/judge/pt/problems/view/1048
//URI 1048 - Aumento de Salário
#include <bits/stdc++.h>
using namespace std;

int main(){
    double k, a, b;
    int c;
    cin >> k;
    if(k <= 400){
        a = k*1.15;
        b = a - k;
        c = 15;
    }
    else if(k <= 800){
        a = k*1.12;
        b = a - k;
        c = 12;
    }else if(k <= 1200){
        a = k*1.10;
        b = a - k;
        c = 10;
    }
    else if(k <= 2000){
        a = k*1.07;
        b = a - k;
        c = 7;
    }else{
        a = k*1.04;
        b = a - k;
        c = 4;
    }
    printf("Novo salario: %.2lf\n", a);
    printf("Reajuste ganho: %.2lf\n", b);
    printf("Em percentual: %d %\n", c);

    return 0;
}