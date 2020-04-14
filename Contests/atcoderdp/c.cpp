#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int main(){
    int n;
    cin >> n;
    int grid[n+1][3];
    for(int i = 0; i < n ; ++i) cin >> grid[i][0] >> grid[i][1] >> grid[i][2];

    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    for(int i = 1; i <= n ; ++i){
        for(int j = 0 ; j < 3 ; ++j){
            for(int k = 0; k < 3 ; ++k){
                if(j == k) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k]+grid[i-1][j]);
            }
        }
    }
    printf("%d\n", max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}