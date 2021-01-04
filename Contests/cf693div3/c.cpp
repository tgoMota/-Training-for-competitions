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
 vector<ll> v;
vector<ll> memo;
ll solve(int idx, const int N){
  if(idx >= N) return 0LL;
  ll& ans = memo[idx];
  if(ans != -1) return ans;
  return ans = solve(idx+v[idx], N)+v[idx];
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        v.assign(n, 0LL);
        for(ll& x : v){
          scanf("%lld", &x);
        }
        
      memo.assign(n+1, -1);
      ll ans = 0LL;
      for(int i = 0; i < n ; ++i){
        ans = max(ans, solve(i, n));
      }
      printf("%lld\n", ans);
    }
    return 0;
}