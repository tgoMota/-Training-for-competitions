//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1015
#include <bits/stdc++.h>
using namespace std;
#define oo 10300

int n, m, tab[101][101], maxp, sump;

int main(){
    while(scanf("%d%d", &m, &n)){
        if(m == 0 && n == 0) break;
        for(int i = 0; i < m ; ++i){
            for(int j = 0; j < n ; ++j){
                cin >> tab[i][j];
                if(tab[i][j] == 1) tab[i][j] = -oo;
                else tab[i][j] = 1;
                if(j != 0) tab[i][j] += tab[i][j-1];
            }
        }
        maxp = -oo;
        for(int i = 0; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                sump = 0;
                for(int row = 0; row < m ; ++row){
                    if(i > 0) sump += tab[row][j] - tab[row][i-1];
                    else sump += tab[row][j];
                    if(sump < 0) sump = 0;
                    maxp = max(maxp, sump);
                }
            }
        }
        printf("%d\n", maxp);
    }

    return 0;
}
