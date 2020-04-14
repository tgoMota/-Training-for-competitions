//Two solution (DP)
// #include <bits/stdc++.h>
// using namespace std;
// #define oo 0x3f3f3f3f
// #define ooll 0x3f3f3f3f3f3f3f3f
// typedef long long ll;
// int main(){
//     int n, s;
//     cin >> n >> s;
//     int weight[n+1], price[n+1];
//     int sum = 0;
//     for(int i = 0; i < n ; ++i){
//          cin >> weight[i] >> price[i];
//          sum+=price[i];
//     }
//     vector<ll> dp(sum+1, ooll);
//     dp[0] = 0LL;
//     for(int i = 0; i < n ; ++i){
//         for(int j = sum-price[i] ; j >= 0 ; --j){
//             dp[j+price[i]] = min(dp[j+price[i]], dp[j]+weight[i]);
//         }
//     }

//     ll ans = 0;
//     for(int i = 0; i <= sum ; ++i){
//         if(dp[i] <= s) ans = max(ans, (ll)i);
//     }

//     printf("%lld\n", ans);
 
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooll 0x3f3f3f3f3f3f3f3f
typedef long long ll;
int main(){
    int n, s;
    cin >> n >> s;
    int weight[n+1], price[n+1];
    int sum = 0;
    for(int i = 1; i <= n ; ++i){
         cin >> weight[i] >> price[i];
         sum+=price[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(sum+1, ooll));
    dp[0][0] = 0LL;
    for(int i = 1; i <= n ; ++i){
        for(int j = 0 ; j <= sum ; ++j){
            if(j < price[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i-1][j-price[i]] + weight[i]);
        }
    }

    ll ans = 0LL;
    for(int i = 1; i <= n ; ++i){
        for(int j = 0; j <= sum ; ++j) if(dp[i][j] <= s){
            ans = max(ans, (ll)j);
        }
    }

    printf("%lld\n", ans);
 
    return 0;
}