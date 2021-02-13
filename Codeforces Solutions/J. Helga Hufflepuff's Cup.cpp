//J. Helga Hufflepuff's Cup
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
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
vector<vector<vector<ll>>> memo;
vector<vector<int>> adj;
int n, m, k, x;
void dfs(int v, int p){
	//flag 0 -> less than k
	//flag 1 -> equal to k
	//flag 2 -> greater than k
	memo[v][0][0] = k-1;
	memo[v][1][1] = 1;
	memo[v][0][2] = m-k;
	for(int u : adj[v]){
		if(u == p) continue;
		dfs(u, v);
		vector<vector<ll>> dp(x+1, vector<ll>(3, 0LL));
		for(int took = 0; took <= x ; ++took){
			for(int take = 0; take <= x-took ; ++take){
				int tot = took + take;
				ll val0 = (memo[u][take][0] + memo[u][take][1] + memo[u][take][2])%mod;
				ll val1 = memo[u][take][0]%mod;
				ll val2 = (memo[u][take][0] + memo[u][take][2])%mod;
				dp[tot][0] = (dp[tot][0] + (memo[v][took][0]*val0)%mod)%mod;
				dp[tot][1] = (dp[tot][1] + (memo[v][took][1]*val1)%mod)%mod;
				dp[tot][2] = (dp[tot][2] + (memo[v][took][2]*val2)%mod)%mod;
			}
		}
		memo[v] = dp;
	}
}

int main(){
    scanf("%d%d", &n, &m);
    adj.assign(n+1, vector<int>());
    for(int i = 0; i < n-1 ; ++i){
      int a, b;
      scanf("%d%d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    scanf("%d%d", &k, &x);
    memo.assign(n+1, vector<vector<ll>>(x+1, vector<ll>(3, 0LL)));
	dfs(1,0);
    ll ans = 0LL;
	for(int i = 0; i <= x ; ++i){
		for(int j = 0; j < 3 ; ++j){
			ans = (ans + memo[1][i][j]) % mod;
		}
	}
	printf("%lld\n", ans);
    return 0;
}