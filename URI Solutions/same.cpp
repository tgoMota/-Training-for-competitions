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
int N, K;
vector<int> ans;
struct CentroidDec{
  int N;
  vector<int> lv, size, sub_tree, dist_cent, dist_sub, parent;
  vector<bool> isCentroid;
  vector<vector<int>> tree;
  CentroidDec(){}
  CentroidDec(const int n){
    N = n;
    size.assign(n+1, 0);
    isCentroid.assign(n+1, false);
    tree.assign(n+1, vector<int>());
    lv.assign(n+1, 0);
    parent.assign(n+1, 0);
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

  void dfs1(int v, int p){
    size[v] = 1;
    dist_cent.push_back(lv[v]);
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        lv[x] = lv[v] + 1;
        dfs1(x,v);
        size[v] += size[x];
      }
    }
  }

  void dfs2(int v, int p){
    sub_tree.push_back(v);
    size[v] = 1;
    dist_sub.push_back(lv[v]);
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        dfs2(x,v);
        size[v] += size[x];
      }
    }
  }

  int dfs_aux(int v, int p){
    size[v] = 1;
    parent[v] = 0;
    for(int x : tree[v]){
      if(x != p && !isCentroid[x]){
        size[v] += dfs_aux(x, v);
        if(!parent[v] || size[parent[v]] < size[x]) parent[v] = x;
      }
    }
    return size[v];
  }

  int getCentroid(int v){
    dfs_aux(v, -1);
    int n = size[v];
    while(size[parent[v]]*2 > n) v = parent[v];
    isCentroid[v] = true;
    return v;
  }

  void decompose(int v){
    int cent_root = getCentroid(v);
    dist_cent.clear();
    lv[cent_root] = 0;
    dfs1(cent_root, -1);
    sort(dist_cent.begin(), dist_cent.end());
    int d = upper_bound(dist_cent.begin(), dist_cent.end(), K) -  dist_cent.begin()-1;
    ans[cent_root] += d;
    for(int x : tree[cent_root]){
      if(!isCentroid[x]){
        sub_tree.clear();
        dist_sub.clear();
        dfs2(x,v);
        sort(dist_sub.begin(), dist_sub.end());

        for(int node : sub_tree){
          int add = upper_bound(dist_cent.begin(), dist_cent.end(), K-lv[node])-dist_cent.begin();
          int minus = upper_bound(dist_sub.begin(), dist_sub.end(), K-lv[node])-dist_sub.begin();
          //trace(d, add, minus, cent_root);
          ans[node] += add - minus;
        }
      }
    }

    for(int x : tree[cent_root]){
      if(!isCentroid[x]) decompose(x);
    }
  }
};
int main(){
    fastio();
    cin >> N >> K;
    CentroidDec cd(N);
    for(int i = 0; i < N-1 ; ++i){
      int a, b;
      cin >> a >> b;
      cd.add_edge(a,b);
    }
    ans.assign(N+1, 0);
    cd.decompose(1);
    for(int i = 1; i <= N ; ++i) cout << ans[i]+1 << '\n';
    return 0;
}
