//M. Journey
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
typedef pair<ll,ll> pll;
//CHECK THE CONSTRAINTS, PLEASE
vector<vector<int>> parent;
vector<vector<ii>> adj;
int n, m;
ll t;
vector<vector<int>> memo;
 
int solve(int v, int cnt){
  if(cnt == n) return v == n ? 0 : oo;
  int& ans = memo[v][cnt];
  if(ans != -1) return ans;
  ans = oo;
  for(ii x : adj[v]){
    ans = min(ans, min(oo, x.second+solve(x.first, cnt+1)));
  }
  return ans;
}
 
void recover(int v, int cnt){
  if(cnt == n){
    cout << v << '\n';
    return;
  }
 
  int& ans = memo[v][cnt];
  for(ii x : adj[v]){
    if(x.second + solve(x.first, cnt+1) == ans){
      cout << v << " ";
      recover(x.first, cnt+1);
      return;
    }
  }
}
 
int main(){
    fastio();
    cin >> n >> m >> t;
    adj.assign(n+1, vector<ii>());
    for(int i = 0; i < m ; ++i){
      int a, b;
      ll c;
      cin >> a >> b >> c;
      adj[a].push_back({b,c});
    }
    parent.assign(n+1, vector<int>(n+1, -1));
    memo.assign(n+1, vector<int>(n+1, -1));
    int pos = 1;
    for(int i = 1; i <= n ; ++i){
      if(solve(1, i) <= t){
        pos = i;
        break;
      }
    }
 
    cout << n-pos+1 << '\n';
    recover(1, pos);
    return 0;
}
