//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1210
//UVA 10269 - Adventure of Super Mario
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
vector<vector<int>> adj;
vector<vector<int>> floyd;

struct edge{
  int v, boots, dist;
  edge(){}
  edge(int _v, int _boots, int _dist){
    v = _v;
    boots = _boots;
    dist = _dist;
  }

  bool operator < (const edge& a) const {
    return dist > a.dist;
  }
};

int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> A >> B >> M >> L >> K;
        const int N = A+B;
        adj.assign(N+1, vector<int>(N+1, oo));
        floyd.assign(N+1, vector<int>(N+1, oo));
        for(int i = 0; i < M ; ++i){
          int a, b, c;
          cin >> a >> b >> c;
          adj[a][b] = adj[b][a] = c;
          floyd[a][b] = floyd[b][a] = c;
        }
        for(int k = 1; k <= A ; ++k){
          for(int i = 1; i <= N ; ++i){
            for(int j = 1; j <= N ; ++j){
              floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
          }
        }

        int dp[N+1][K+1];
        memset(dp, 0x3f, sizeof(dp));
        bool vst[N+1][K+1];
        memset(vst, false, sizeof(vst));
        priority_queue<edge> pq;
        pq.push(edge(N, 0, 0));
        dp[N][0] = 0;
        while(!pq.empty()){
          auto e = pq.top();
          pq.pop();
          int v = e.v;
          int boots = e.boots;
          if(vst[v][boots]) continue;
          vst[v][boots] = true;
          for(int u = 1; u <= N ; ++u){
            if(dp[u][boots] > dp[v][boots] + adj[v][u]){
              dp[u][boots] = dp[v][boots] + adj[v][u];
              pq.push(edge(u, boots, dp[u][boots]));
            }
            if(boots < K && dp[u][boots+1] > dp[v][boots] && floyd[v][u] <= L){
              dp[u][boots+1] = dp[v][boots];
              pq.push(edge(u, boots+1, dp[u][boots+1]));
            }
          }
        }

        int ans = oo;
        for(int i = 0; i <= K ;  ++i){
          ans = min(ans, dp[1][i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
