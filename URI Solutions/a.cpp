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
//CHECK THE LIMITS, PLEASE
vector<bool> circle;
vector<vector<ll>> memo;
bool valid(int a, int b, int c){
  return (circle[a] + circle[b] + circle[c]) <= 1;
}
ll solve(int l, int r){
  if(r - l < 2) return 1;
  if(r - l == 2) return valid(l,l+1,r);
  ll& ans = memo[l][r];
  if(ans != -1LL) return ans;
  ans = 0;
  for(int i = l+1; i <= r ; i+=3){
    for(int j = i+1; j <= r ; j+=3){
      if(valid(l, i, j)) ans += solve(l+1, i-1)*solve(i+1, j-1)*solve(j+1,r);
    }
  }
  return ans;
}

int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        string line;
        cin >> line;
        circle.assign(n, false);
        for(int i = 0; i < n; ++i) circle[i] = (line[i] == 'R');
        memo.assign(n+1, vector<ll>(n+1, -1LL));
        cout << "Case " << ti << ": " << solve(0,n-1) << '\n';
    }
    return 0;
}
