//https://codeforces.com/contest/321/problem/C
//Codeforces | C. Ciel the Commander
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
  vector<vector<int>> tree;
  vector<vector<int>> decomposedTree;
  vector<int> size;
  vector<bool> isCentroid;
  vector<char> lv;
  int N;
  CentroidDec(){}
  CentroidDec(const int n){
    N = n+1;
    tree.assign(N, vector<int>());
    decomposedTree.assign(N, vector<int>());
    isCentroid.assign(N, false);
    lv.assign(N, 'A');
    size.assign(N, 0);
  }

  void add_edge(int u, int v){
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  void dfs(int v, int p){
    size[v] = 1;
    for(int x : tree[v]){
      if(!isCentroid[x] && x != p){
        dfs(x, v);
        size[v]+=size[x];
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
    dfs(v,v);
    int centroid_root = getCentroid(v, v, size[v]);
    isCentroid[centroid_root] = true;
    return centroid_root;
  }

  int decomposeTree(int root){
    int centroid_root = getCentroid(root);
    for(int x : tree[centroid_root]){
      if(!isCentroid[x]){
        int centroid_sub = decomposeTree(x);
        decomposedTree[centroid_root].push_back(centroid_sub);
        decomposedTree[centroid_sub].push_back(centroid_root);
      }
    }
    return centroid_root;
  }
  void dfsDec(int v, int p){
    for(int x : decomposedTree[v]){
      if(x != p){
        lv[x] = lv[v] + 1;
        dfsDec(x, v);
      }
    }
  }
};

int n;
int main(){
    fastio();
    cin >> n;
    CentroidDec cd(n);
    for(int i = 0; i < n-1 ; ++i){
      int a, b;
      cin >> a >> b;
      cd.add_edge(a,b);
    }
    int root = cd.decomposeTree(1);
    cd.dfsDec(root,root);
    for(int i = 1; i <= n ; ++i){
      cout << cd.lv[i] << " ";
    }
    cout << '\n';
    return 0;
}
