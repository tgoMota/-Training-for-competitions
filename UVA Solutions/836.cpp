//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=777
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int n, subm, maxm, matriz[26][26];
string m[700];

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        cin >> m[0];
        n = m[0].size();
        for(int i = 0; i < n ; ++i){
            matriz[0][i] = m[0][i] - '0';
            if(matriz[0][i] == 0) matriz[0][i] = -630;
            if(i != 0) matriz[0][i] = matriz[0][i] + matriz[0][i-1];
        }

        for(int i = 1; i < n; ++i) {
            cin >> m[i]; 
            for(int j = 0 ; j < n ; ++j){
                matriz[i][j] = m[i][j] - '0';
                if(matriz[i][j] == 0) matriz[i][j] = -630;
                if(i != 0) matriz[i][j] = matriz[i][j] + matriz[i][j-1];
            }
        }

        maxm = -oo;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                subm = 0;
                for(int row = 0; row < n ; ++row){
                    if(i > 0) subm += matriz[row][j] - matriz[row][i-1];
                    else subm += matriz[row][j];
                    if(subm < 0) subm = 0;
                    maxm = max(maxm, subm);
                }
            }
        }

        printf("%d\n", maxm);
        if(t) printf("\n");
    }
    return 0;
}