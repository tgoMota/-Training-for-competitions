//https://www.urionlinejudge.com.br/judge/pt/problems/view/1476
//1476 - Caminhão (DSU Approach)
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
struct edge{
  int u, v, w;
  edge(){}
  edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w){}
};

vector<int> p, ans, rnk;
vector<edge> edges;
vector<set<int>> querys;
int N, M, Q;

void init(int n){
  p.resize(n+1);
  rnk.resize(n+1);
  for(int i = 1; i <= n ; ++i) p[i] = i, rnk[i] = 0;
}

int find(int u){
  if(p[u] == u) return u;
  return p[u] = find(p[u]);
}

void merge(int u, int v, int w){
  int x = find(u), y = find(v);
  if(x == y) return;
  if(rnk[x] < rnk[y]) swap(x,y);
  p[y] = x;
  for(int q : querys[y]){
    if(querys[x].count(q)){
      if(ans[q] == -1) ans[q] = w;
    }
    else querys[x].insert(q);
  }
  querys[y].clear();
  if(rnk[x] == rnk[y]) rnk[x]++;
}

void mst(){
  init(N);
  sort(edges.begin(), edges.end(), [&](edge& a, edge& b){
    return a.w > b.w;
  });

  for(auto e : edges){
    int u = e.u;
    int v = e.v;
    int w = e.w;

    merge(u,v,w);
  }
}
int main(){
    fastio();
    while(cin >> N >> M >> Q){
      edges.resize(M);
      for(auto& e : edges){
        cin >> e.u >> e.v >> e.w;
      }
      querys.assign(N+1, set<int>());
      for(int i = 0; i < Q ; ++i){
        int u, v;
        cin >> u >> v;
        querys[u].insert(i);
        querys[v].insert(i);
      }
      ans.assign(Q, -1);
      mst();
      for(int i = 0; i < Q ; ++i) cout << ans[i] << '\n';
    }
    return 0;
}