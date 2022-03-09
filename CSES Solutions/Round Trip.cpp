//https://cses.fi/problemset/task/1669/
//Round Trip
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
vector<vector<int>> adj;
vector<int> p, ans;
vector<bool> vst;
int first;
bool dfs(int v, int pp){
  vst[v] = true;
  p[v] = pp;
  for(int x : adj[v]){
    if(vst[x] && x != pp){
      ans.push_back(x);
      for(int u = v; u != x ; u = p[u]) ans.push_back(u);
      ans.push_back(x);
      return true;
    }
    if(!vst[x] && dfs(x, v)) return true;
  }
  return false;
}

int main(){
    fastio();
    int n, m;
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    for(int i = 0; i < m ; ++i){
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vst.assign(n+1, false);
    p.assign(n+1, -1);
    for(int i = 1; i <= n ; ++i){
      if(vst[i]) continue;
      if(!dfs(i,i)) continue;
      cout << (int)ans.size() << '\n';
      for(int i = 0; i < (int)ans.size()-1 ; ++i) cout << ans[i] << ' ';
      cout << ans.back() << '\n';
      return 0;
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}

