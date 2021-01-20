//https://codeforces.com/contest/1350/problem/B
//B. Orac and Models
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
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<int> v(n+1);
        for(int i = 1; i <= n ; ++i) scanf("%d", &v[i]);
        vector<int> dp(n+1, 1);
        int ans = 1;
        for(int i = 1; i <= n ; ++i){
          for(int j = 1; i*j<=n ; j++){
            if(v[i*j] <= v[i]) continue;
            dp[i*j] = max(dp[i*j], dp[i]+1);
            ans = max(ans, dp[i*j]);
          }
        }

        printf("%d\n", ans);
        
    }
    return 0;
}
