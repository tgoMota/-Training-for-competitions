//https://codeforces.com/problemset/problem/293/E
//Codeforces | E. Close Vertices
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define all(x) x.begin(),x.end()
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<ll,int> ii;
//CHECK THE CONSTRAINTS, PLEASE

struct SegmentTree{
    int N;
    vector<vector<int>>tree;
    SegmentTree(vector<ii>&a){
        N = (int)a.size();
        tree.assign(4*N, vector<int>());
        build(1,0,N-1,a);
    }
    void build(int i, int l, int r, vector<ii>&a){
        if(l == r){
            tree[i].push_back(a[l].second);
            return;
        }
        int m = l + (r-l)/2;
        build(2*i, l, m, a );
        build(2*i+1, m+1, r, a );
        merge(all(tree[2*i]), all(tree[2*i+1]), back_inserter(tree[i]));
    }
    int query(int i, int l, int r, int ql, int qr, int hi){
        if(qr < l || ql > r) return 0;
        if(ql <= l && r <= qr) return upper_bound(all(tree[i]),hi)-tree[i].begin();
        int m = l + (r-l)/2;
        return query(2*i,l,m,ql,qr,hi) + query(2*i+1,m+1,r,ql,qr,hi);
    }
    int query(int a, int val){
    	return query(1,0,N-1,0,a,val);
    }
};

int N, L, W;
ll ans;
struct CentroidDec{
  vector<bool> isCentroid;
  vector<int> size, lv;
  vector<vector<ii>> adj;
  vector<ll> nodes_sub, sum;
  vector<pair<ll,int>> sum_root, sum_sub;
  CentroidDec(){}
  CentroidDec(const int n){
    sum.assign(n+1, 0LL);
    isCentroid.assign(n+1, false);
    adj.assign(n+1, vector<ii>());
    size.assign(n+1, 0);
    lv.assign(n+1, 0);
  }

  void add_edge(int u, int v, int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  void dfs(int v, int p){
    size[v] = 1;
    for(auto x : adj[v]){
      int u = x.first;
      if(!isCentroid[u] && u != p){
        dfs(u, v);
        size[v] += size[u];
      }
    }
  }

  void dfs1(int v, int p, ll s, int len){
    lv[v] = len;
    sum[v] = s;
    if(s <= W && len <= L) sum_root.push_back({s,len});
    for(auto x : adj[v]){
      int u = x.first;
      if(!isCentroid[u] && u != p){
        dfs1(u, v, s+x.second, len+1);
      }
    }
  }

  void dfs2(int v, int p, ll s, int len){
    sum_sub.push_back({s,len});
    nodes_sub.push_back(v);
    for(auto x : adj[v]){
      int u = x.first;
      if(!isCentroid[u] && u != p){
        dfs2(u, v, s+x.second, len+1);
      }
    }
  }

  int getCentroid(int v, int p, int n){
    bool is_centroid = true;
    int heavy_child = 0;
    for(auto x : adj[v]){
      int u = x.first;
      if(!isCentroid[u]  && u != p){
        if(size[u] > n/2) is_centroid = false;
        if(heavy_child == 0 || size[heavy_child] < size[u]) heavy_child = u;
      }
    }

    if(is_centroid && size[v] >= n/2) return v;
    return getCentroid(heavy_child, v, n);
  }

  int getCentroid(int v){
    dfs(v, -1);
    int centroid = getCentroid(v, -1, size[v]);
    isCentroid[centroid] = true;
    return centroid;
  }

  int solveQuery(vector<ii>& a, SegmentTree& st, int w, int l){ //p(x,)
      int lo = 0, hi = (int)a.size();
      while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(a[mid].first > w) hi = mid;
        else lo = mid+1;
      }
      if(lo == 0) return 0;
    	return st.query(lo-1,l);
  }

  void decompose(int v){
    sum_root.clear();
    int cent_root = getCentroid(v);
    dfs1(cent_root, -1, 0LL, 0);
    sort(sum_root.begin(), sum_root.end(), [](auto& a, auto& b){
      if(a.first == b.first) return a.second < b.second;
      return a.first < b.first;
    });
    ans += (int)sum_root.size()-1;
    SegmentTree stA(sum_root);
    for(auto x : adj[cent_root]){
      if(isCentroid[x.first]) continue;
      nodes_sub.clear();
      sum_sub.clear();
      int u = x.first;
      dfs2(u, cent_root, sum[u], 1);
      sort(sum_sub.begin(), sum_sub.end(), [](auto& a, auto& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
      });
      SegmentTree stB(sum_sub);
      for(int y : nodes_sub){
        int plus = 0, minus = 0;
        plus = solveQuery(sum_root, stA, W-sum[y], L-lv[y]);
        minus = solveQuery(sum_sub, stB, W-sum[y], L-lv[y]);
        ans += plus-minus;
      }
    }

    for(auto x : adj[cent_root]){
      if(!isCentroid[x.first]) decompose(x.first);
    }
  }
};
int main(){
    fastio();
    cin >> N >> L >> W;
    CentroidDec cd(N);
    for(int i = 2; i <= N ; ++i){
      int a, b;
      cin >> a >> b;
      cd.add_edge(i,a,b);
    }
    ans = 0LL;
    cd.decompose(1);
    cout << ans/2 << '\n';
    return 0;
}
