//https://www.urionlinejudge.com.br/judge/pt/problems/view/1134
//URI 1134 - Tipo de Combustível
#include <bits/stdc++.h>
using namespace std;

int main(){
    int al = 0, g = 0, d =0, k;
    do{
        cin >> k;
        if(k == 1) al++;
        else if(k == 2) g++;
        else if(k==3) d++;

    }while(k != 4);
    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", al, g, d);
    return 0;
}