//https://www.urionlinejudge.com.br/judge/pt/problems/view/1476
//URI 1476 - Caminhão
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
int n, m, s;
vector<vector<ii>> adj;
struct edge{
  int u, v, w;
  edge(int _u, int _v, int _w){
    u = _u;
    v = _v;
    w = _w;
  }
  edge(){}
};
vector<edge> edges;
vector<int> parent;

void init(){
  parent.resize(n);
  for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
  return u == parent[u] ? u : find(parent[u]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);
  parent[u] = v;
}

void mst(){
  sort(edges.begin(),edges.end(), [&](edge& a, edge& b){
    return a.w > b.w;
  });
  init();
  adj.assign(n+1, vector<ii>());
  for(auto e : edges){
    int u = e.u;
    int v = e.v;
    int w = e.w;
    if(find(u) == find(v)) continue;
    merge(u,v);
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  edges.clear();
  parent.clear();
}
vector<vector<int>> memo, mindist;
vector<int> lv;
void dfs(int v, int p, int it){
  memo[v][0] = p;
  mindist[v][0] = (it == -1 ? oo : adj[p][it].second);
  const int logn = (int)log2(n)+1;
  for(int i = 1; i <= logn ; ++i){
    memo[v][i] = memo[memo[v][i-1]][i-1];
    mindist[v][i] = min(mindist[v][i-1], mindist[memo[v][i-1]][i-1]);
  }
  for(int i = 0; i < (int)adj[v].size() ; ++i){
    auto x = adj[v][i];
    if(x.first == p) continue;
    lv[x.first] = lv[v]+1;
    dfs(x.first, v, i);
  }
}

int solve(int u, int v){
    const int log = (int)log2(n)+1;
    int min_edge = oo;
    if(lv[u] < lv[v]) swap(u,v);
    int diff = lv[u]-lv[v];
    for(int i = 0; i <= log ; ++i){
        if((1<<i) & diff) {
          min_edge = min(min_edge, mindist[u][i]);
          u = memo[u][i];
        }
    }
    if(u == v) return min_edge;
    for(int i = log ; i >= 0 ; --i){
        if(memo[u][i] != memo[v][i]){
            min_edge = min({min_edge, mindist[u][i], mindist[v][i]});
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    min_edge = min({min_edge, mindist[u][0], mindist[v][0]});
    return min_edge;
}

int main(){
    fastio();
    while(cin >> n >> m >> s){
      for(int i = 0; i < m ; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a-1,b-1,c});
      }

      mst();
      lv.assign(n+1, 0);
      const int logn = (int)log2(n)+1;
      memo.assign(n+1, vector<int>(logn+1, 0));
      mindist.assign(n+1, vector<int>(logn+1, oo));
      dfs(0, 0, -1);
      for(int i = 0; i < s ; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << solve(u,v) << '\n';
      }
    }
    return 0;
}

