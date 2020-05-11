//https://onlinejudge.org/external/122/12238.pdf
//UVA 12238 - Ants Colony
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<vector<pii>> adj;
vector<vector<int>> parent;
vector<int> deg;
vector<ll> dist;

void dfs(int u, int p, const int& log){
    parent[u][0] = p;
    for(int i = 1; i <= log ; ++i){
        parent[u][i] = parent[parent[u][i-1]][i-1];
    }

    for(auto x : adj[u]){
        if(x.first == u || x.first == p) continue;
        deg[x.first] = deg[u]+1;
        dist[x.first] = dist[u] + x.second;
        dfs(x.first, u, log);
    }
}

int lca(int u, int v, const int& log){
    if(deg[u] < deg[v]) swap(u,v);

    for(int i = log ; i >= 0 ; --i){
        if(deg[u]-(1<<i) >= deg[v]) u = parent[u][i];
    }

    if(u == v) return u;

    for(int i = log; i >= 0 ; --i){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}


int main(){
    int n;
    while(scanf("%d", &n) && n){
        const int log = (int)ceil(log2(n));
        adj.assign(n+1, vector<pii>());
        parent.assign(n+1, vector<int>(log+1, -1));
        deg.assign(n+1, 0);
        dist.assign(n+1, 0);
        for(int i = 1; i <= n - 1 ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back({i,b});
            adj[i].push_back({a,b});
        }
        dfs(0,0,log);
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q ; ++i){
            int a,b;
            scanf("%d%d", &a, &b);
            int lc = lca(a,b,log);
            ll ans = dist[a]+dist[b]-2*dist[lc];
            printf("%lld", ans);
            if(i != q-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}