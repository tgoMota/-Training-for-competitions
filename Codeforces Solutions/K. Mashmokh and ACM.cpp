//K. Mashmokh and ACM
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
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0LL));
    for(int i = 1; i <= n ; ++i) dp[i][0] = 1;

    for(int i = 1; i < k ; ++i){
      for(int j = 1 ; j <= n ; ++j){
        for(int w = 1; j*w <= n ; ++w){
          dp[j*w][i] = (dp[j*w][i] + dp[j][i-1])%mod;
        }
      }
    }

    ll ans = 0LL;
    for(int i = 1; i <= n ; ++i){
      ans = (ans + dp[i][k-1])%mod;
    }
    printf("%lld\n", ans);
    return 0;
}
