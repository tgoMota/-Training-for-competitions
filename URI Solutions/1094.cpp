//https://www.urionlinejudge.com.br/judge/pt/problems/view/1094
//URI 1094 - Experiências
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, co = 0, ra = 0, sa = 0, tot = 0, sum = 0, k;
    char c;
    cin >> n;
    while(n--){
        cin >> k >> c;
        if(c == 'C') co+=k;
        else if(c == 'R') ra+=k;
        else if(c == 'S') sa+=k;
        sum+=k;
    }

    printf("Total: %d cobaias\n", sum);
    printf("Total de coelhos: %d\n", co);
    printf("Total de ratos: %d\n", ra);
    printf("Total de sapos: %d\n", sa);
    printf("Percentual de coelhos: %.2lf %\n", (co/(double)sum)*100.00);
    printf("Percentual de ratos: %.2lf %\n", (ra/(double)sum)*100.00);
    printf("Percentual de sapos: %.2lf %\n", (sa/(double)sum)*100.00);

    return 0;
}