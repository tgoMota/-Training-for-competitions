//https://codeforces.com/contest/1461/problem/B
//B. Find the Spruce
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        ll ans = 0LL;
        for(int i = 1; i <= n ; ++i){
          string line;
          cin >> line;
          for(int j = 1; j <= m ; ++j){
            if(line[j-1] == '*') dp[i][j] = dp[i][j-1] + 1;
          }
          for(int j = 1; j <= m ; ++j){
            dp[i][j] = min((dp[i][j]+1)>>1, dp[i-1][j-1]+1);
            ans += dp[i][j];
          }
        }

        cout << ans << '\n';
    }
    return 0;
}
