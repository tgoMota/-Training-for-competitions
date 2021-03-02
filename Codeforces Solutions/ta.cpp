#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
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
typedef pair<ll,int> ii;
//CHECK THE CONSTRAINTS, PLEASE

class SegmentTree
{
public:
    int N, sz;
    vector<vector<int>>tree;
    SegmentTree( vector<ii>&a )
    {
        N = a.size();
        sz = 4*N;
        tree.resize(sz);
        build(0,0,N-1,a);
    }
    void build( int v, int l, int r, vector<ii>&a )
    {
        if( l == r )
        {
            tree[v] = {a[l].second};
            return;
        }
        int m = l + (r-l)/2;
        build( 2*v+1, l, m, a );
        build( 2*v+2, m+1, r, a );
        merge( all(tree[2*v+1]), all(tree[2*v+2]), back_inserter(tree[v]) );
    }
    int query( int v, int l, int r, int ql, int qr, int lo, int hi )
    {
        if(qr < l || ql > r) return 0;
        if(ql <= l && r <= qr){
        	int num = upper_bound(all(tree[v]),hi) - lower_bound(all(tree[v]),lo);
        	return num;
        }
        int m = l + (r-l)/2;
        return query(2*v+1,l,m,ql,qr,lo,hi) + query(2*v+2,m+1,r,ql,qr,lo,hi);
    }
    int get( int l, int r, int a, int b){
    	return query(0,0,N-1,l,r,a,b);
    }
};

int N, L, W;
struct CentroidDec{
  vector<bool> vst, isCentroid;
  vector<int> size;
  vector<vector<ii>> adj;
  vector<ll> nodes_root, nodes_sub; 
  vector<ll> sum;
  vector<pair<ll,int>> sum_root, sum_sub;
  vector<int> ans, lv;
  CentroidDec(){}
  CentroidDec(const int n){
    vst.assign(n+1, false);
    sum.assign(n+1, 0LL);
    isCentroid.assign(n+1, false);
    adj.assign(n+1, vector<ii>());
    size.assign(n+1, 0);
    ans.assign(n+1, 0);
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
    nodes_root.push_back(v);
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
    vst.assign(N+1, false);
    dfs(v, -1);
    int centroid = getCentroid(v, -1, size[v]);
    isCentroid[centroid] = true;
    return centroid;
  }

  int getQuery(vector<ii>& a, SegmentTree& st, int l1, int l2, int r1, int r2){
      ii temp = {l1,0};
    	int l = lower_bound(a.begin(), a.end(),temp) - a.begin();
    	temp = {l2+1,0};
    	int r = lower_bound(a.begin(), a.end(),temp) - a.begin() - 1;
    	if(l > r) return 0;
    	int ans = st.get(l,r,r1,r2);
      return ans;
  }

  void decompose(int v){
    nodes_root.clear();
    sum_root.clear();
    int cent_root = getCentroid(v);
    dfs1(cent_root, -1, 0LL, 0);
    sort(sum_root.begin(), sum_root.end(), [](auto& a, auto& b){
      if(a.first == b.first) return a.second < b.second;
      return a.first < b.first;
    });
    //int d = upper_bound(sum_root.begin(), sum_root.end(), W)-sum_root.begin()-1;
    int d = (int)sum_root.size()-1;
    ans[cent_root] += d;
   // trace(cent_root, d);
    //sgA.build(1, 0, (int)sum_root.size()-1, sum_root);
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
        int plus = 0, minus = 0, plus2 = 0, minus2 = 0;
        // cout << "sum_root: ";
        // for(auto sr : sum_root){
        //   cout << "{" << sr.first << ", " << sr.second << "} ";
        //   if(sr.first <= W-sum[y] && sr.second <= L-lv[y]) plus2++;
        // }
        // cout << "\nsum_sub: ";
        // for(auto sr : sum_sub){
        //   cout << "{" << sr.first << ", " << sr.second << "} ";
        //   if(sr.first <= W-sum[y] && sr.second <= L-lv[y]) minus2++;
        // }
        //plus = upper_bound(sum_root.begin(), sum_root.end(), make_pair(W-sum[y],0))-sum_root.begin();
        //minus = upper_bound(sum_sub.begin(), sum_sub.end(), make_pair(W-sum[y], 0))-sum_sub.begin();
        plus = getQuery(sum_root, stA, 0, W-sum[y], 0, L-lv[y]);
        minus = getQuery(sum_sub, stB, 0, W-sum[y], 0, L-lv[y]);
        // plus = sgA.query(1,0,(int)sum_root.size()-1, 0, (int)sum_root.size()-1, L-lv[y]);
        // minus = sgB.query(1,0,(int)sum_sub.size()-1, 0, (int)sum_sub.size()-1, L-lv[y]);
        //plus = _search(sum_root, sgA, L-lv[y], W-sum[y]);
        //minus = _search(sum_sub, sgB, L-lv[y], W-sum[y]);
        //trace(cent_root, y, plus, minus,plus2, minus2, L-lv[y], W-sum[y]);
        ans[y] += plus-minus;
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

    cd.decompose(1);
    ll answer = 0LL;
    for(int i = 1; i <= N ; ++i) {
     answer += cd.ans[i];
    }
    cout << answer/2 << '\n';
    return 0;
}
