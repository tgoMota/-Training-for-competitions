//https://codeforces.com/contest/1454/problem/E
//E. Number of Simple Paths
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

vector<vector<int>> adj;
vector<bool> cycle, vst;
vector<int> parent, sz;
int n;

bool dfs(int u, int p){
    vst[u] = true;
    for(int& v : adj[u]){
        if(v == p) continue;
        if(vst[v]){
            for(int t = u; t != v ; t = parent[t]){
                cycle[t] = true;
            }
            cycle[v] = true;
            return true;
        }else{
            parent[v] = u;
            if(dfs(v, u)) return true;
        }
    }
    return false;
}

void solve(int u, int p){
    sz[u] = 1;
    for(int& v : adj[u]){
        if(cycle[v] || v == p) continue;
        solve(v, u);
        sz[u]+=sz[v];
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        adj.assign(n, vector<int>());
        parent.assign(n, -1);
        sz.assign(n, 0);
        cycle.assign(n, false);
        vst.assign(n, false);
        for(int i = 0; i < n ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(0, -1);
        ll ans = 1LL * n*(n-1);
        for(int i = 0; i < n ; ++i){
            if(!cycle[i]) continue;
            solve(i, -1);
            ans -= 1LL*sz[i]*(sz[i]-1)/2;
            trace(i, ans);
        }
        printf("%lld\n", ans);
    }

    return 0;
}