//https://www.urionlinejudge.com.br/judge/pt/problems/view/1131
//URI 1131 - Grenais
#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int in, gr, c, wi = 0, wg = 0, em = 0, g = 0;
    do{
        cin >> in >> gr;
        if(in > gr) wi++;
        else if(in < gr) wg++;
        else em++;
        printf("Novo grenal (1-sim 2-nao)\n");
        g++;
    }while(cin >> c && c == 1);
    printf("%d grenais\n", g);
    printf("Inter:%d\n", wi);
    printf("Gremio:%d\n", wg);
    printf("Empates:%d\n", em);
    if(wi > wg) printf("Inter venceu mais\n");
    else if(wi < wg) printf("Gremio venceu mais\n");
    else printf("Nao houve vencedor\n");

    return 0;
}