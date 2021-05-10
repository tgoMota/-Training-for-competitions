//https://www.urionlinejudge.com.br/judge/pt/problems/view/1123
//URI 1123 - Desvio de Rota
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
int n, m, c, d;
vector<vector<ll>> adj;
vector<ll> sum;

int dji(){
  int source = d;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  vector<ll> dist(n+1, oo);
  pq.push({0,source});
  dist[source] = 0;
  while(!pq.empty()){
    auto x = pq.top();
    int dv = x.first;
    int v = x.second;
    pq.pop();
    for(int u = 0; u < n ; ++u){
      if(adj[v][u] == oo) continue;
      int w = adj[v][u];
      if(u < c-1){
        dist[c-1] = min(dist[c-1], dist[v]+sum[u]+adj[v][u]);
      }else{
        if(dist[v]+w < dist[u]){
          dist[u] = dist[v]+w;
          pq.push({dist[u], u});
        }
     }
    }
  }
  return dist[c-1];
}

int main(){
    fastio();
    while(cin >> n >> m >> c >> d && n){
      adj.assign(n+1, vector<ll>(n+1, oo));
      sum.assign(n+1, oo);
      for(int i = 0; i < m ; ++i){
        int u, v, x;
        cin >> u >> v >> x;
        adj[u][v] = adj[v][u] = (ll)x;
      }
      sum[c-1] = 0;
      for(int i = c-2; i >= 0; i--){
        sum[i]=sum[i+1] + adj[i][i+1];
      }

      cout << dji() << '\n';
    }
    return 0;
}

