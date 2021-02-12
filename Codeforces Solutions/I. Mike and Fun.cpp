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
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    vector<vector<int>> v(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n ; ++i){
      for(int j = 1; j <= m ; ++j){
        scanf("%d", &v[i][j]);
      }
    } 
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n ; ++i){
      int mxmx = 0, mx = 0;
      for(int j = 1; j <= m ; ++j){
        if(!v[i][j]) mx = 0;
        else mx++;
        mxmx = max(mxmx, mx); 
      }
      dp[i] = mxmx;
    }
    while(q--){
      int a, b;
      scanf("%d%d", &a, &b);
      v[a][b] = 1 - v[a][b];
      int mx = 0, mxmx = 0;
      for(int j = 1; j <= m ; ++j){
        if(!v[a][j]) mx = 0;
        else mx++;
        mxmx = max(mxmx, mx);
      }
      dp[a] = mxmx;
      int ans = 0;
      for(int i = 1; i <= n ; ++i) ans = max(ans, dp[i]);
      printf("%d\n", ans);
    }
    return 0;
}
