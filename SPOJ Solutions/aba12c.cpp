//https://www.spoj.com/problems/ABA12C/
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int memo[110][1010], c, n, k, prices[110];

int pd(int resta, int kg){
    if(kg == 0) return 0;
    if(resta <= 0 || kg < 0) return oo;
    int& ans = memo[resta][kg];
    if(ans != -1) return ans;
    ans = oo;
    for(int i = 1; i <= k ; ++i){
        if(prices[i] == -1) continue;
        ans = min(ans, pd(resta-1, kg-i) + prices[i]);
    }
    return ans;

}
int main(){ 
    cin >> c;
    while(c--){
        memset(memo, -1, sizeof(memo));
        cin >> n >> k;
        for(int i = 1; i <= k ; ++i) cin >> prices[i];
        int ans = pd(n, k) == oo ? -1 : pd(n,k);
        cout << ans << endl;
    }

    return 0;
}