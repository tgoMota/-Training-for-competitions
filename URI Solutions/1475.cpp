//https://www.urionlinejudge.com.br/judge/pt/problems/view/1475
//URI 1475 - Remendo
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
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
int n, c, r1, r2;
vector<ll> pos, dp;

ll solve(int posBegin, ll sum){
  int cur = upper_bound(pos.begin(), pos.end(), sum)-pos.begin();
  if(cur-posBegin>=n) return 0;
  ll& ans = dp[cur];
  if(ans != -1) return ans;
  return ans = min(r1+solve(posBegin, pos[cur]+r1), r2+solve(posBegin, pos[cur]+r2));
}

int main(){
    fastio();
    while(cin >> n >> c >> r1 >> r2){
      pos.resize(2*n);
      for(int i = 0; i < n ; ++i) cin >> pos[i];
      for(int i = n; i < 2*n ; ++i) pos[i] = pos[i-n]+c;
      ll ans = ooLL;
      for(int i = 0; i < n ; ++i){
        dp.assign(2*n, -1);
        ans = min(ans, solve(i, pos[i]-1));
      }

      cout << ans << '\n';
    }
    return 0;
}

