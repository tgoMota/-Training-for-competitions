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
const int N = 200002;

typedef pair<ll, ll> pll;
vector <pll> g[N], qs[N];
vector <ll> me, tot, nodes;
int cnt[N], bc[N], ans[N];
ll h[N];
bool mark[N];

int dfs(int v, bool c = 0, int par = -1, ll di = 0)
{
	h[v] = di;
	cnt[v] = 1;
	bc[v] = 0;
	me.push_back(di);
	nodes.push_back(v);
	if(c)
		tot.push_back(di);
	for(int i = 0; i < g[v].size(); i++)
	{
		pll e = g[v][i];
		int u = e.first;
		if(u != par && !mark[u])
		{
			cnt[v] += dfs(u, c, v, di + e.second);
			if(!bc[v] || cnt[bc[v]] < cnt[u])
				bc[v] = u;
		}
	}
	return cnt[v];
}

void solve(int v)
{
	dfs(v);
	int n = cnt[v];
	while(cnt[bc[v]] * 2 > n)
		v = bc[v];
	tot.clear();
	dfs(v, 1);
	mark[v] = 1;
	sort(tot.begin(), tot.end());
	int d;
	for(int _i = 0; _i < qs[v].size(); _i++)
	{
		pll q = qs[v][_i];
		ll w = q.first;
		int i = q.second;
		d = upper_bound(tot.begin(), tot.end(), w) - tot.begin() - 1;
		ans[i] += d;
	}
	for(int _i = 0; _i < g[v].size(); _i++){
		pll e = g[v][_i];
		if(!mark[e.first]){
			me.clear();
			nodes.clear();
			dfs(e.first, 0, v, e.second);
			sort(me.begin(), me.end());
			for(int j = 0; j < nodes.size(); j++)
			{
				int u = nodes[j];
				for(int k = 0; k < qs[u].size(); k++)
				{
					pll q = qs[u][k];
					ll w = q.first;
					int i = q.second;
					int add = upper_bound(tot.begin(), tot.end(), w - h[u]) - tot.begin();
					int minus = upper_bound(me.begin(), me.end(), w - h[u]) - me.begin();
					trace(d, add, minus, v);
					ans[i] += add;
					ans[i] -= minus;
				}
			}
		}
	}
	for(int i = 0; i < g[v].size(); i++)
		if(!mark[g[v][i].first])
			solve(g[v][i].first);
	mark[v] = 0;
}

 int main(){
	fastio();
	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++)
	{
		int u, v, w = 1;
		cin >> u >> v;
		g[u].push_back(pll(v, w));
		g[v].push_back(pll(u, w));
	}
	for(int i = 1; i <= n; i++)
	{
		qs[i].push_back(make_pair(k, i));
	}
	solve(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] + 1 << endl;
	return 0;
 }