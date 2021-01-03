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
    int n, m;
    scanf("%d%d", &n, &m);
    adj.assign(n+1, vector<int>());
    vst.assign(n+1,false);
    for(int i = 0; i < m ; ++i){
      int a, b;
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    dfs(1);
    bool ok = true;
    for(int i = 1; i <= n ; ++i){
      if(!vst[i]) ok = false;
    }
    printf("%s\n", ok ? "COMPLETO" : "INCOMPLETO");
    return 0;
}
