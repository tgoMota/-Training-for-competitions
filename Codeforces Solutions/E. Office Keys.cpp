//E. Office Keys
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
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);
    vector<ll> a(n);
    for(ll& x : a) scanf("%lld", &x);
    vector<ll> b(k);
    for(ll& x : b) scanf("%lld", &x);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<vector<ll>> dp(k+1, vector<ll>(n+1, ooLL));
    dp[0][0] = 0LL;
    for(int i = 1; i <= k ; ++i){
      for(int p = 0; p <= n ; ++p){
        dp[i][p] = min(dp[i][p], dp[i-1][p]);
        ll dist = abs(a[p-1]-b[i-1]) + abs(b[i-1]-d);
        if(p) dp[i][p] = min(dp[i][p], max(dist, dp[i-1][p-1]));
      }
    }

    printf("%lld\n", dp[k][n]);
    return 0;
}
