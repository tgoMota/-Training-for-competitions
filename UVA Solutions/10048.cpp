//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989
//UVA 10048 - Audiophobia
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<pair<int,ii>> edges;
vector<int> parent, memo;
vector<vector<ii>> go;

void init(const int n){
    parent.resize(n);
    for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
    return parent[u] == u ? parent[u] : find(parent[u]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    parent[y] = x;
}


void kruskal(const int n){
    init(n);
    go.assign(n, vector<ii>());
    sort(edges.begin(), edges.end());
    for(int i = 0; i < (int)edges.size() ; ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)) continue;

        go[u].push_back({v, w});
        go[v].push_back({u, w});
        merge(u, v);
    }
}

int dfs(int idx, const int destiny){
    if(idx == destiny) return 0;
    int& ans = memo[idx];
    if(ans != -1) return ans;
    ans = oo;
    for(auto x : go[idx]){
        ans = min(ans, 1+dfs(x.first, destiny));
    }
    return ans;
}

int rec(int idx, const int destiny){
    if(idx == destiny) return 0;
    int maxd = 0;
    for(auto x : go[idx]){
        if(memo[idx] == dfs(x.first, destiny)+1){
            maxd = max(x.second, rec(x.first, destiny));
            break;
        }
    }
    return maxd;
}

int main(){
    int n, m, q, t = 0;
    while(scanf("%d%d%d", &n, &m, &q) && n+m+q){
        if(t) printf("\n");
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            edges.push_back({c,{a, b}});
        }
        printf("Case #%d\n", ++t);
        kruskal(n);
        for(int i = 0; i < q; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            memo.assign(n, -1);
            dfs(a, b);
            int ans = rec(a, b);
            if(ans) printf("%d\n", ans);
            else printf("no path\n");
        }
    }
    return 0;
}