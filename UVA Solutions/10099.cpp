//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1040
//UVA 10099 - The Tourist Guide
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<pair<int,ii>> edges;
vector<vector<ii>> go;
vector<int> memo, parent;

void init(const int n){
    parent.resize(n);
    for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
    return parent[u] == u ? u : find(parent[u]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    parent[y] = x;
}

void kruskal(const int n){
    init(n);
    go.assign(n, vector<ii>());
    sort(edges.begin(), edges.end(), greater<pair<int,ii>>());
    for(int i = 0; i < edges.size() ; ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)) continue;

        go[u].push_back({v,w});
        go[v].push_back({u,w});
        merge(u,v);
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
    if(idx == destiny) return oo;
    int ans = oo;
    for(auto x : go[idx]){
        if(memo[idx] == 1+dfs(x.first, destiny)){
            ans = min(x.second, rec(x.first, destiny));
            break;
        }
    }
    return ans;
}

int main(){
    int n, m, t = 0;
    while(scanf("%d%d", &n, &m) && n+m){
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--, c--;
            edges.push_back({c,{a,b}});
        }

        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        kruskal(n);
        memo.assign(n, -1);
        dfs(a,b);
        printf("Scenario #%d\n", ++t);
        printf("Minimum Number of Trips = %d\n\n", (c-1)/rec(a,b)+1);
    }
    
    return 0;
}