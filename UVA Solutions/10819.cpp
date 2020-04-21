#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int n, m, p[101],f[101], memo[101][10201][2];

int pd(int money, int ind, bool used){
    if(money > m) {
        if(used || m + 200 < money || money <= 2000 && ind > n) return -oo;
        if(money > 2000 ) used = true, money-=200;
    }
    if(ind > n) return 0;
    int& ans = memo[ind][money][used];
    if(ans != -1) return ans;
    return ans = max(pd(money, ind+1, used), f[ind] + pd(money + p[ind], ind+1, used));
}

int main(){

    while(scanf("%d%d", &m, &n) != EOF){
        memset(memo, -1, sizeof(memo));
        for(int i = 1; i <= n ; ++i){
            scanf("%d%d", &p[i], &f[i]);
        }
        int ans = pd(0,1, false);
        printf("%d\n", ans < 0 ? -1 : ans);
    }

    return 0;
}
