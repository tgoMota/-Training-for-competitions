//https://codeforces.com/contest/342/problem/E
//Codeforces | E. Xenia and Tree
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


struct CentroidDec{
  int N, log;
  vector<vector<int>> tree, memo, decTree;
  vector<int> size, parent, lv;
  vector<bool> isCentroid;
  CentroidDec(){}
  CentroidDec(const int n){
    N = n+1;
    tree.assign(N, vector<int>());
    decTree.assign(N, vector<int>());
    size.assign(N, 0);
    isCentroid.assign(N, false);
    parent.assign(N, -1);
  }

  void add_edge(int u, int v){
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  void dfs(int v, int p){
    size[v] = 1;
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        dfs(x, v);
        size[v] += size[x];
      }
    }
  }

  int getCentroid(int v, int p, int n){
    bool is_centroid = true;
    int heaviest_child = 0;
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        if(size[x] > n/2) is_centroid = false;
        if(heaviest_child == 0 || size[x] > size[heaviest_child]) heaviest_child = x;
      }
    }
    if(is_centroid && n-size[v] <= n/2) return v;
    return getCentroid(heaviest_child, v, n);
  }

  int getCentroid(int v){
    dfs(v, -1);
    int centroid = getCentroid(v, -1, size[v]);
    isCentroid[centroid] = true;
    return centroid;
  }

  int decomposeTree(int v){
    int cent_root = getCentroid(v);
    for(int x : tree[cent_root]){
      if(!isCentroid[x]){
        int cent_sub = decomposeTree(x);
        parent[cent_sub] = cent_root;
        decTree[cent_root].push_back(cent_sub);
        decTree[cent_sub].push_back(cent_root);
      }
    }
    return cent_root;
  }

  
  void dfsLCA(int v, int p){
    memo[v][0] = p;
    for(int i = 1; i <= log ; ++i){
      memo[v][i] = memo[memo[v][i-1]][i-1];
    }

    for(int x : tree[v]){
      if(x != p){
        lv[x] = lv[v]+1;
        dfsLCA(x,v);
      }
    }
  }

  int lca(int u, int v){
    if(lv[u] < lv[v]) swap(u,v);
    int dif = lv[u]-lv[v];
    for(int i = 0; i <= log ; ++i){
      if((1<<i) & dif){
        u = memo[u][i];
      }
    }

    if(u == v) return u;
    for(int i = log; i >= 0; --i){
      if(memo[v][i] != memo[u][i]){
        v = memo[v][i];
        u = memo[u][i];
      }
    }
    return memo[v][0];
  }

  void buildLCA(int root){
    lv.assign(N, 0);
    log = (int)log2(N)+1;
    memo.assign(N, vector<int>(log+1, -1));
    dfsLCA(root,root);
  }


  int dist(int u, int v){
    if(u == v) return 0;
    return (lv[u] + lv[v] - 2*lv[lca(u,v)]);
  }
}; 

CentroidDec cd;
vector<int> best;
 
void dfs_update(int v, const int p){
  if(v == -1) return;
  best[v] = min(best[v], cd.dist(v,p));
  dfs_update(cd.parent[v], p);
}
void update(int v){
  if(best[v] == 0) return;
  best[v] = 0;
  dfs_update(cd.parent[v],v);
}

int get(int v, int q){
  return v == -1 ? oo : min(best[v] + cd.dist(v,q),get(cd.parent[v],q));
}

int N, M;
int main(){
    fastio();
    cin >> N >> M;
    cd = CentroidDec(N);
    for(int i = 0; i < N-1 ; ++i){
      int a, b;
      cin >> a >> b;
      cd.add_edge(a,b);
    }
    
    best.assign(N+1, oo);
    int root = cd.decomposeTree(1);
    cd.buildLCA(root);
    update(1);
    for(int i = 0; i < M ; ++i){
      int a, b;
      cin >> a >> b;
      if(a == 1) update(b);
      else cout << get(b,b) << '\n';
    }
    cout << '\n';
    return 0;
}
