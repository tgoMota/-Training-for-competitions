//https://codeforces.com/contest/1467/problem/D
//D. Sum of Paths
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
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);
    vector<ll> v(n+1);
    for(int i = 1; i <= n ; ++i) scanf("%lld", &v[i]);
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0LL));
    vector<ll> cnt(n+1, 0);
    for(int i = 1; i <= n ; ++i) dp[i][0] = 1LL;
    for(int j  = 1; j <= k ; ++j){
      for(int i = 1; i <= n ; ++i){
        dp[i][j] += i-1 >= 1 ? dp[i-1][j-1] : 0LL;
        dp[i][j] %= mod;
        dp[i][j] += i+1 <= n ? dp[i+1][j-1] : 0LL;
        dp[i][j] %= mod;
      }
    }

    for(int i = 1; i <= n ; ++i){
      for(int j = 0; j <= k ; ++j){
        cnt[i] += dp[i][j] * dp[i][k-j];
        cnt[i] %= mod;
      }
    }

    ll ans = 0LL;
    for(int i = 1; i <= n ; ++i){
      ans += v[i]*cnt[i];
      ans %= mod;
    }
    while(q--){
      ll a, b;
      scanf("%lld%lld", &a, &b);
      ans -= (v[a]*cnt[a])%mod;
      ans = (ans + mod)%mod;
      v[a] = b;
      ans += v[a]*cnt[a];
      ans %= mod;
      printf("%lld\n", ans);
    }

    return 0;
}
