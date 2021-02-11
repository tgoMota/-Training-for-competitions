//C. Vitamins
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
vector<ii> v;
int main(){
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n ; ++i){
      cin >> v[i].first;
      string s;
      cin >> s;
      int mask = 0;
      for(int i = 0; i < (int)s.size() ; ++i){
        if(s[i] == 'A') mask = mask | (1<<0);
        else if(s[i] == 'B') mask = mask | (1<<1);
        else mask = mask | (1<<2);
      }
      v[i].second = mask;
    }
    int fullmask = (1<<3)-1;
    vector<vector<int>> dp(n+1, vector<int>(fullmask+1, oo));
    dp[0][0] = 0;
    for(int i = 0; i < n ; ++i){
      int cost = v[i].first;
      int mask = v[i].second;
      for(int j = 0; j <= fullmask ; ++j){
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        dp[i+1][j | mask] = min(dp[i+1][j | mask], cost + dp[i][j]);
      }
    }

    printf("%d\n", dp[n][fullmask] == oo ? -1 : dp[n][fullmask]);

    return 0;
}
