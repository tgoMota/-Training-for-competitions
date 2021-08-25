//https://codeforces.com/problemset/problem/698/A
//A. Vacations
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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n ; ++i) cin >> v[i];

    //gym => 0
    //contest => 1
    //rest = 2
    vector<vector<int>> dp(n+1, vector<int>(3,oo));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= n ; ++i){
      dp[i][2] = 1+min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
      if(v[i-1] == 1) dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
      else if(v[i-1] == 2) dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
      else if(v[i-1] == 3) dp[i][1] = min(dp[i-1][0], dp[i-1][2]), dp[i][0] = min(dp[i-1][1], dp[i-1][2]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';

    return 0;
}
