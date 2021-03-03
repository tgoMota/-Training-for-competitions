//https://codeforces.com/contest/161/problem/D
//Codeforces | D. Distance in Tree
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
vector<vector<int>> tree, dp;

int N, K;
ll dfs(int v, int p){
  dp[v][0] = 1;
  ll ans = 0LL;
  for(int x : tree[v]){
    if(x == p) continue;
    ans += dfs(x, v);
    for(int i = 0; i < K ; ++i) ans += dp[v][i] * dp[x][K-i-1];
    for(int i = 0; i < K ; ++i) dp[v][i+1] += dp[x][i];
  }
  return ans;
}
int main(){
    fastio();
    cin >> N >> K;
    tree.assign(N+1, vector<int>());
    for(int i = 0; i < N-1 ; ++i){
      int a, b;
      cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    dp.assign(N+1, vector<int>(K+1, 0));
    cout << dfs(1,-1) << '\n';
    return 0;
}
