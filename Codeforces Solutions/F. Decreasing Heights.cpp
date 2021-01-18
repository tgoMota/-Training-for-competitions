//https://codeforces.com/contest/1353/problem/F
//F. Decreasing Heights
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
const int NAX = 102;
ll grid[NAX][NAX];
ll cost(int i, int j, int ai, int aj){
    ll c = grid[ai][aj] + (i+j) - (ai+aj);
    if(c > grid[i][j]) return ooLL;
    return grid[i][j]-c;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n ; ++i){
          for(int j = 0; j < m; ++j){
            scanf("%lld", &grid[i][j]);
          }
        }
        ll ans = ooLL;

        for(int ai = 0; ai < n ; ++ai){
          for(int aj = 0; aj < m ; ++aj){
            vector<vector<ll>> dp(n, vector<ll>(m, ooLL));
            dp[0][0] = 0;
            for(int i = 0; i < n ; ++i){
              for(int j = 0; j < m ; ++j){
                if(i) dp[i][j] = min(dp[i][j],dp[i-1][j]);
                if(j) dp[i][j] = min(dp[i][j], dp[i][j-1]);
                dp[i][j] += cost(i,j,ai,aj);
              }
            }
            ans = min(ans,dp[n-1][m-1]);
          }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
