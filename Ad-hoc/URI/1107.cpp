//https://www.urionlinejudge.com.br/judge/pt/problems/view/1107
//URI 1107 - Escultura à Laser
#include <bits/stdc++.h>
using namespace std;
int grid[10002][10002];
int main(){
    int a, c, k;
    while(scanf("%d%d", &a, &c) && a+c){
        for(int i = 1; i <= a ; ++i)
            for(int j = 1; j <= c ; ++j) grid[i][j] = 1;
        for(int i = 1; i <= c ; ++i){
            scanf("%d", &k);
            for(int j = a; j > a- k ; --j) grid[j][i] = 0;
        }
        int cont = 0, div = 1;
        for(int i = a; i >= 1 ; --i){
            for(int j = 1; j <= c ; ++j){
                if(!div && !grid[i][j]) div = 1;
                if(div && grid[i][j]){
                    cont++;
                    div = 0;
                }
            }
            div = 1;
        }

        printf("%d\n", cont);
    }

    return 0;
}