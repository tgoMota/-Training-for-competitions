//https://www.urionlinejudge.com.br/judge/pt/problems/view/1312
//URI 1312 - Empilhamento de Bolas
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
//CHECK THE CONSTRAINTS, PLEASE
int n;
vector<vector<int>> grid;
vector<vector<ll>> dp;
int main(){
    fastio();
    while(cin >> n && n){
        grid.assign(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <= n ; ++i)
          for(int j = 1; j <= i ; ++j)
            cin >> grid[i][j];
       
        dp.assign(n+2, vector<ll>(n+2, 0LL));
        for(int j = 1; j <= n ; ++j)
          for(int i = j; i <= n ; ++i)
            dp[i][j] += dp[i-1][j] + grid[i][j];

        for(int j = n-1; j >= 1 ; --j){
          ll add = max(0LL, dp[j][j+1]);
          for(int i = j; i <= n ; ++i){
            add = max(add, dp[i+1][j+1]);
            dp[i][j] += add;
          }
        }

        ll ans = 0LL;
        for(int i = 1; i <= n ; ++i) ans = max(ans, dp[i][1]);
        cout << ans << '\n';
    }
    return 0;
}

