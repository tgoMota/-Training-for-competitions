//https://www.urionlinejudge.com.br/judge/pt/problems/view/1329
//URI 1329 - Cara ou Coroa
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n){
        int coin[n], m = 0, j = 0; 
        for(int i = 0; i < n ; ++i){
            scanf("%d", &coin[i]);
            if(coin[i]) j++;
            else m++;
        } 
        printf("Mary won %d times and John won %d times\n", m, j);
    }

    return 0;
}