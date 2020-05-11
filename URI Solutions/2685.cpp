//https://www.urionlinejudge.com.br/judge/pt/problems/view/2685
//URI 2685 - A Mudança
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        n %= 360;
        if(n >= 0 && n < 90) printf("Bom Dia!!\n");
        else if(n >= 90 && n < 180) printf("Boa Tarde!!\n");
        else if(n >= 180 && n < 270) printf("Boa Noite!!\n");
        else printf("De Madrugada!!\n");
    }

    return 0;
}