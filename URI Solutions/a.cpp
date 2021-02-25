#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
//CHECK THE LIMITS, PLEASE

struct CentroidDec{
    int N;
    vector<vector<int>> originalTree;
    vector<vector<int>> tree;
    vector<bool> vst, isCentroid;
    vector<int> size;
    CentroidDec(){}
    CentroidDec(const int n){
        N = n+1;
        originalTree.assign(N, vector<int>());
        tree.assign(N, vector<int>());
        isCentroid.assign(N, false);
    }
    
    void addEdge(int u, int v){
        originalTree[u].push_back(v);
        originalTree[v].push_back(u);
    }

    void dfs(int v){
        vst[v] = true;
        size[v] = 1;
        for(int x : originalTree[v]){
            if(!vst[x] && !isCentroid[x]){
                dfs(x);
                size[v] += size[x];
            }
        }
    }

    int getCentroid(int v, const int n){
        bool is_centroid = true;
        vst[v] = true;
        int heaviest_child = 0;
        for(int x : originalTree[v]){
            if(!vst[x]  && !isCentroid[x]){
                if(size[x] > n/2) is_centroid = false;
                if(heaviest_child == 0 || size[x] > size[heaviest_child]) heaviest_child = x;
            }
        }
        if(is_centroid && n-size[v] <= n/2) return v;
        return getCentroid(heaviest_child, n);
    }
    
    int getCentroid(int v){
        vst.assign(N, false);
        size.assign(N, 0);
        dfs(v);
        vst.assign(N, false);
        int centroid = getCentroid(v, size[v]);
        isCentroid[centroid] = true;
        return centroid;
    }

    int decomposeTree(int root){
        int centroid_root = getCentroid(root);
        cout << centroid_root << " ";
        for(int x : originalTree[centroid_root]){
            if(!isCentroid[x]){
                int centroid_subtree = decomposeTree(x);
                tree[centroid_root].push_back(centroid_subtree);
                tree[centroid_subtree].push_back(centroid_root);
            }
        }
        return centroid_root;
    }
};
int N, K;
int main(){
    fastio();
    cin >> N >> K;
    CentroidDec cd(N);
    for(int i = 0; i < N-1 ; ++i){
      int a, b;
      cin >> a >> b;
      cd.addEdge(a,b);
    }
    cd.decomposeTree(8);
    for(int i = 1; i <= N ; ++i){
      cout << i << ": ";
      for(int x : cd.tree[i]) cout << x << " ";
      cout << '\n';
    }
    return 0;
}

