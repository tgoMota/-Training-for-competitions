//https://cses.fi/problemset/task/1666
//Building Roads
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
vector<bool> vst;

void dfs(int v){
  vst[v] = true;
  for(int x : adj[v]){
    if(vst[x]) continue;
    dfs(x);
  }
}
int main(){
    fastio();
    int n,m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    for(int i = 0; i < m ; ++i){
      int a, b;
      cin >> a >> b;
      a--, b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vst.assign(n, false);
    dfs(0);
    vector<int> vans;
    for(int i = 1 ; i < n ; ++i){
      if(!vst[i]){
        dfs(i);
        vans.push_back(i+1);
      }
    }

    cout << (int)vans.size() << '\n';
    for(int x : vans){
      cout << 1 << ' ' << x << '\n';
    }
    return 0;
}

