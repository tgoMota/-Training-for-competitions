#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> parent;
vector<int> lv;

void dfs(int u, int p, const int log){
    parent[u][0] = p;
    for(int i = 1; i <= log ; ++i){
        parent[u][i] = parent[parent[u][i-1]][i-1];
    }

    for(int x : adj[u]){
        if(x != u && x != p){
            lv[x] = lv[u]+1;
            dfs(x, u, log);
        }
    }
}

int lca(int u, int v, const int log){
    if(lv[u] < lv[v]) swap(u,v);

    for(int i = log; i >= 0 ; --i){
        if(lv[u]- (1 << i) >= lv[v]) u = parent[u][i];
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

int getParent(int u, int level){
    for(int i = log2(lv[u]); i >= 0 ; --i){
        if(lv[u] - (1<<i) >= level) u = parent[u][i];
    }
    return u;
}


int main(){
    int n;
    while(scanf("%d", &n) && n){
        adj.assign(n+1, vector<int>());
        lv.assign(n+1, 0);
        for(int i = 0; i < n - 1;  ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int log = (int)ceil(log2(n));

        int l;
        scanf("%d", &l);
        parent.assign(n+1, vector<int>(log+1, -1));
        dfs(1,1,log);

        for(int i = 0; i < l ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);

            int lc = lca(a,b,log);
            int d = lv[a] + lv[b] - 2*lv[lc];
            int mid = lv[a] > lv[b] ? getParent(a, lv[a]-d/2) : getParent(b, lv[b]-d/2);

            if(d % 2)
                printf("The fleas jump forever between %d and %d.\n", min(mid, parent[mid][0]), max(mid, parent[mid][0]));
            else
                printf("The fleas meet at %d.\n", mid);
            
        }
    }
    return 0;
}