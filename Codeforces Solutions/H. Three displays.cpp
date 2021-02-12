//H. Three displays
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
    int n;
    scanf("%d", &n);
    vector<ll> a(n), b(n);
    for(ll& x : a) scanf("%lld", &x);
    for(ll& x : b) scanf("%lld", &x);
    const int k = 3;
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, ooLL));
    ll ans = ooLL;
    for(int i = 0; i < n ; ++i){
      dp[i][0] = b[i];
      for(int j = 1; j < k ; ++j){
        for(int w = 0; w < i ; ++w){
          if(a[i] > a[w]){
            dp[i][j] = min(dp[i][j], b[i] + dp[w][j-1]);
            if(j == k-1) ans = min(ans, dp[i][j]);
          }
        }
      }
    }
    printf("%lld\n", ans == ooLL ? -1 : ans);


    return 0;
}
