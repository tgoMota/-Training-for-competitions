//G. Covered Path
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
    int a, b;
    scanf("%d%d", &a, &b);
    int t, d;
    scanf("%d%d", &t, &d);
    vector<vector<int>> dp(t+1, vector<int>(a + t*d + 1, -oo));
    dp[0][a] = a;
    for(int i = 1; i < t ; ++i){
      for(int v = 0; v <= a + t*d ; ++v){
        for(int z = -d ; z <= d ; ++z){
          if(v + z < 0 || v + z > a+t*d) continue;
          dp[i][v] = max(dp[i][v],v+dp[i-1][v+z]);
        }
      }
    }

    printf("%d\n", dp[t-1][b]);
    return 0;
}
