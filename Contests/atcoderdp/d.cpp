#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef long long ll;
int main(){
    int n, s;
    cin >> n >> s;
    int weight[n+1], price[n+1];
    for(int i = 1; i <= n ; ++i) cin >> weight[i] >> price[i];
 
    vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0LL));
 
    for(int i = 1; i <= n ; ++i){
        for(int j = 0; j <= s ; ++j){
            if(j < weight[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], price[i]+dp[i-1][j-weight[i]]);
        }
    }
    printf("%lld\n", dp[n][s]);
 
    return 0;
}