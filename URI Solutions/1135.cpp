//https://www.urionlinejudge.com.br/judge/pt/problems/view/1135
//URI 1135 - Colônia de Formigas
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<vector<ii>> adj;
vector<vector<int>> memo;
vector<int> lv;
vector<ll> sum;

void dfs(int v, int p, const int logn){
    lv[v] = lv[p]+1;
    memo[v][0] = p;
    for(int i = 1; i <= logn ; ++i){
        memo[v][i] = memo[memo[v][i-1]][i-1];
    }

    for(auto& x : adj[v]){
        if(x.first == v || lv[x.first] != 0) continue;
        sum[x.first] += sum[v] + x.second;
        dfs(x.first, v, logn);
    }
}

int lca(int u, int v, const int n){
    const int logn = (int)log2(n)+1;
    if(lv[u] < lv[v]) swap(u,v);
    int dif = lv[u]-lv[v];
    for(int i = 0; i <= logn ; ++i){
        if((1<<i) & dif) u = memo[u][i];
    }
    if(u == v) return u;
    for(int i = logn ; i >= 0 ; --i){
        if(memo[u][i] != memo[v][i]){
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    return memo[u][0];
}

void build(const int n){
    const int logn = (int)log2(n)+1;
    memo.assign(n, vector<int>(logn+1, -1));
    lv.assign(n, 0);
    sum.assign(n,0);
    dfs(0,0,logn);
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        adj.assign(n, vector<ii>());
        for(int i = 1; i <= n-1 ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back({i,b});
            adj[i].push_back({a,b});
        }

        int q;
        scanf("%d", &q);
        build(n);
        while(q--){
            int a, b;
            scanf("%d%d", &a, &b);
            int lc = lca(a,b,n);
            ll ans = sum[a] + sum[b] - 2*sum[lc];
            printf("%lld", ans);
            if(q) printf(" ");
        }
        printf("\n");
    }

    return 0;
}