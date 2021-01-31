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
int n, s, t;
vector<unordered_map<int,int>> adj;
vector<int> match, color;
vector<bool> vst;
int colorBase, other;
int aug(int v){
  if(vst[v] || color[v] == other) return 0;
  vst[v] = true;
  for(auto it : adj[v]){
    int u = it.first;
    //assert(color[u] == 1);
    if(match[u] == -1 || aug(match[u])){
      match[u] = v;
      return 1;
    }
  }
  return 0;
}

int main(){
    while(scanf("%d", &n) != EOF){
      adj.assign(n+3, unordered_map<int,int>());
      for(int i = 1; i <= n ; ++i){
        int a;
        scanf("%d", &a);
        adj[a][i] = 1;
        adj[i][a] = 1;
      }
      color.assign(n+1, -1);
      bool isBipartite = true;
      vector<int> rnk(2,0);
      for(int i = 1; i <= n && isBipartite ; ++i){
        if(color[i] != -1) continue;
        queue<int> q;
        q.push(i);
        color[i] = 0;
        rnk[0] = 1;
        while(!q.empty()){
          int v = q.front();
          q.pop();
          for(auto it : adj[v]){
            int x = it.first;
            if(x == v || color[x] == color[v]){
              isBipartite = false;
              break;
            }
            if(color[x] == -1){
              color[x] = 1 - color[v];
              rnk[color[x]]++;
              q.push(x);
            }
          }
          if(!isBipartite) break;
        }
      }
      if(!isBipartite || (n&1)){
        printf("IMPOSSIBLE\n");
        continue;
      }
    }
    return 0;
}
