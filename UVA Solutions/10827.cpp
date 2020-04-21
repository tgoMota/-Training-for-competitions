//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1768
#include <bits/stdc++.h>
using namespace std;
int tab[152][152], n, t, maxsum, maxrect;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < n ; ++j){
                cin >> tab[i][j];
                tab[i][j+n] = tab[i][j];
                tab[i+n][j+n] = tab[i][j];
                if(j > 0) tab[i][j] += tab[i][j-1];
                tab[i+n][j] = tab[i][j];
            }
        }
        for(int i = 0; i < 2*n ; ++i)
            for(int j = n ; j < 2*n ; ++j)
                tab[i][j] += tab[i][j-1];
            
        maxrect = INT_MIN;
        for(int i = 0; i < n ; ++i){
            for(int j = i; j < i+n ; ++j){
                for(int l = 0; l < n ; ++l){
                    maxsum = 0;
                    for(int row = l; row < n+l ; ++row){
                        if(i > 0) maxsum += tab[row][j] - tab[row][i-1];
                        else maxsum += tab[row][j];
                        maxrect = max(maxrect, maxsum);
                        if(maxsum < 0) maxsum = 0;
                    }
                }
            }
        }
        printf("%d\n", maxrect);
    }
    return 0;  
}