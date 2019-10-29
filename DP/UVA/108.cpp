//https:uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int m[101][101], n, maxRect, subRect;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n ; ++i)
        for(int j = 0; j < n ; ++j) {
            cin >> m[i][j];
            if(j > 0) m[i][j] += m[i][j-1];
        }

    maxRect = -oo;
    for(int i = 0; i < n ; ++i)
        for(int j = i; j < n ; ++j){
            subRect = 0;
            for(int row = 0; row < n ; ++row){
                if(i > 0) subRect += m[row][j] - m[row][i-1];
                else subRect += m[row][j];

                if(subRect < 0) subRect = 0;
                maxRect = max(maxRect, subRect);
            }
        }

        printf("%d\n", maxRect);
    
    return 0;
}