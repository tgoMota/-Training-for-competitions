//https://codeforces.com/contest/1286/problem/A
//A. Garland
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n+1);
    for(int i = 1; i <= n ; ++i) scanf("%d", &v[i]);
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n/2+1, vector<int>(2,oo)));
    dp[0][0][0] = dp[0][0][1] = 0;
    for(int i = 1; i <= n ; ++i){
        for(int j = 0; j <= n/2 ; ++j){
            if(v[i] == 0 || v[i] % 2) dp[i][j][1] = min(dp[i-1][j][1], 1+dp[i-1][j][0]);
            if(v[i] % 2 == 0 && j) dp[i][j][0] = min(dp[i-1][j-1][0], 1+dp[i-1][j-1][1]);
        }
    }
    printf("%d\n", min(dp[n][n/2][0], dp[n][n/2][1]));
    return 0;
}