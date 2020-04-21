//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2445
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int n, m, c, memo[21][201], prices[21][21];

int pd(int g, int r){
    if(r >= 0 && g > c) return 0;
    if(r < 0) return -oo;
    int& ans = memo[g][r];
    if(ans != -1) return ans;
    ans = -oo;
    for(int i = 1; i <= prices[g][0] ; ++i)
        ans = max(ans, pd(g+1, r-prices[g][i]) + prices[g][i]);
    return ans;
}

int main(){
    cin >> n;
    while(n--){
        cin >> m >> c;
        for(int i = 1; i <= c ; ++i){
            cin >> prices[i][0];
            for(int j = 1 ; j <= prices[i][0] ; ++j) cin >> prices[i][j];
        }

        memset(memo, -1, sizeof(memo));
        int r = pd(1, m);
        if(r > 0) printf("%d\n", r);
        else printf("no solution\n");
    }

    return 0;
}
