//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2352
//11367 - Full Tank?
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
int n, m;
vector<int> prices;
vector<vector<ii>> adj;

struct edge{
  int cost, fuel, v;
  edge(){}
  edge(int _v, int _cost, int _fuel){
    v = _v;
    cost = _cost;
    fuel = _fuel;
  }

  bool operator < (const edge& a) const{
    if(cost == a.cost) return fuel < a.fuel;
    return cost > a.cost;
  }
};

int main(){
    fastio();
    cin >> n >> m;
    prices.resize(n);
    for(int i = 0; i < n ; ++i) cin >> prices[i];
    adj.assign(n, vector<ii>());
    for(int i = 0; i < m ; ++i){
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].push_back({b,c});
      adj[b].push_back({a,c});
    }
    int q;
    cin >> q;
    while(q--){
      int c, s, d;
      cin >> c >> s >> d; 
      int dp[n+1][c+1];
      memset(dp, 0x3f, sizeof(dp));
      bool vst[n+1][c+1];
      memset(vst, false, sizeof(vst));
      priority_queue<edge> pq;
      pq.push(edge(s,0,0));
      dp[s][0] = 0;
      while(!pq.empty()){
        auto e = pq.top();
        pq.pop();
        int v = e.v;
        int fuel = e.fuel;
        if(vst[v][fuel]) continue;
        vst[v][fuel] = true;
        if(v == d) break;
        for(int i = 0; fuel + i <= c ; ++i){
          int newFuel = fuel + i;
          for(auto x : adj[v]){
            if(x.first == v) continue;
            if(newFuel >= x.second && dp[x.first][newFuel-x.second] > dp[v][fuel] + prices[v]*i){
              dp[x.first][newFuel-x.second] = dp[v][fuel] + prices[v]*i;
              pq.push(edge(x.first, dp[v][fuel] + prices[v]*i, newFuel-x.second));
            }
          }
        }
      }
      int ans = oo;
      for(int i = 0; i <= c ; ++i){
        ans = min(ans, dp[d][i]);
      }
      if(ans == oo) cout << "impossible\n";
      else cout << ans << '\n';
    }

    return 0;
}
