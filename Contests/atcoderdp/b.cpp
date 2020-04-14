#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int main(){
    int n, k;
    cin >> n >> k;
    int v[n];
    for(int i = 0; i < n ; ++i) cin >> v[i];
    vector<int> dp(n+1, oo);
    dp[0] = 0;
    for(int i = 1; i < n ; ++i){
        for(int x = i-1; x >= 0 && x>=i-k ; x--){
            dp[i] = min(dp[i], dp[x]+abs(v[i]-v[x]));
        }
    }
    printf("%d\n", dp[n-1]);

    return 0;
}