#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int t, n, price[1001], wgt[1001], g, mw[101], memo[1001][31];
int pd(int ind, int cap){
    if(cap < 0) return -oo;
    if(ind > n) return 0;
    int& ans = memo[ind][cap];
    if(ans != -1) return ans;
    return ans = max(pd(ind+1, cap-wgt[ind]) + price[ind], pd(ind+1, cap));
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n ; ++i) cin >> price[i] >> wgt[i];
        cin >> g;
        for(int i = 1; i <= g ; ++i) cin >> mw[i];
        int ans = 0, r;
        memset(memo, -1, sizeof(memo));
        for(int i = 1; i <= g ; ++i){
            r = pd(1, mw[i]);
            r = r < 0 ? 0 : r;
            ans += r;
        }
        printf("%d\n", ans);
    }
    return 0;
}