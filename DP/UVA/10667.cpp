#include <bits/stdc++.h>
using namespace std;
#define oo 10201

int tab[101][101], r1, r2, c1, c2, maxRect, maxSum, p, s, b;

int main(){

    cin >> p;
    while(p--){
        cin >> s >> b;
        for(int i = 1; i <= b ; ++i){
            cin >> r1 >> c1 >> r2 >> c2;
            for(int k = r1; k <= r2 ; ++k){
                for(int l = c1 ; l <= c2 ; ++l){
                    tab[k][l] = -oo;
                }
            }
        }
        for(int i = 1; i <= s; ++i){
            for(int j = 1; j <= s; ++j){
                if(tab[i][j] != -oo) tab[i][j] = 1;
                if(j > 1) tab[i][j] += tab[i][j-1];
            }
        }
        
        maxRect = -oo;
        for(int i = 1; i <= s ; ++i){
            for(int j = i ; j <= s ; ++j){
                maxSum = 0;
                for(int row = 1; row <= s ; ++row){
                    if(i > 1) maxSum += tab[row][j] - tab[row][i-1];
                    else maxSum += tab[row][j];
                    if(maxSum < 0) maxSum = 0;
                    maxRect = max(maxRect, maxSum);
                }
            }
        }
        printf("%d\n", maxRect);
        memset(tab, -1, sizeof(tab));
    }

    return 0;
}
