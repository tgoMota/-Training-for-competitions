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
//CHECK THE LIMITS, PLEASE
int A, B, M, L, K;
vector<vector<ii>> adj;

struct edge{
  int dist, remainK, howManyCanRun, curVertex, wasRunning, parent;
  edge(){}
  edge(int _dist, int _remainK, int _howManyCanRun, int _curVertex, int _wasRunning, int _parent){
    dist = _dist;
    remainK = _remainK;
    howManyCanRun = _howManyCanRun;
    curVertex = _curVertex;
    wasRunning = _wasRunning;
    parent = _parent;
  }

  bool operator < (const edge& a) const {
     if(dist == a.dist) return remainK > a.remainK;
     return dist < a.dist;
  }

};

int dji(){
  const int N = A+B;
  int dist[N+1][K+1][2];
  memset(dist, -1, sizeof(dist));
  multiset<edge> mp;
  mp.insert(edge(0, K, 0, N, 0, -1));
  while(!mp.empty()){
    edge e = *mp.begin();
    mp.erase(mp.begin());
    int d = e.dist;
    int r = e.remainK;
    int howManyCanRun = e.howManyCanRun;
    int v = e.curVertex;
    int wasRunning = e.wasRunning;
    int parent = e.parent;
    if(dist[v][r][wasRunning] != -1) continue;
    dist[v][r][wasRunning] = d;
    if(v == 1) return d;
    for(auto x : adj[v]){
      if(x.first == parent) continue;
      if(v <= A && wasRunning && howManyCanRun >= x.second) {
        mp.insert(edge(d, r, howManyCanRun-x.second, x.first, 1, v));
      }
      else if(r > 0 && L >= x.second) {
        mp.insert(edge(d, r-1, L-x.second, x.first,1, v));
      }
      mp.insert(edge(d+x.second, r,0, x.first, 0, v));
    }
  }
  return -1;
}

int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> A >> B >> M >> L >> K;
        const int N = A+B;
        adj.assign(N+1, vector<ii>());
        int dp[N+1][N+1][K+1];
        memset(dp, 0x3f, sizeof(dp));
        for(int i = 0; i < M ; ++i){
          int a, b, c;
          cin >> a >> b >> c;
          adj[a].push_back({b,c});
          adj[b].push_back({a,c});
        }
        
        cout << dji() << '\n';
    }
    return 0;
}
