//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=475
//UVA 534 - Frogger
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f;
typedef pair<int,int> ii;
vector<ii> ps;
vector<int> parent;
vector<pair<double,ii>> edges;
vector<vector<int>> go;

double dist(pair<int,int> p1, pair<int,int> p2){
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int find(int u){
    if(parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

void init(const int n){
    parent.resize(n);
    for(int i = 0; i < n ; ++i) parent[i] = i;
}

void merge(int x, int y){
    x = find(x), y = find(y);
    parent[x] = y; 
}

void kruskal(const int n){
    init(n);
    sort(edges.begin(), edges.end());
    int cnt = 0;
    for(int i = 0 ; i < edges.size() ; ++i){
        auto x = edges[i];
        double w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)) continue;
        merge(u,v);
        go[u].push_back(v);
        go[v].push_back(u);
        if(++cnt == n-1) break;
    }
}
vector<int> memo;
int dfs(int idx){
    if(idx == 1) return 0;
    int& ans = memo[idx];
    if(ans != -1) return ans;
    ans = oo;
    for(int x : go[idx]){
        ans = min(ans, dfs(x)+1);
    }
    return ans;
}

double rec(int idx){
    if(idx == 1) return 0.0;
    double ans = 0.0;
    for(int x : go[idx]){
        if(dfs(x)+1 == memo[idx]){
            return ans = max({ans, dist(ps[idx], ps[x]), rec(x)});
        }
    }
    return ans;
}

int main(){
    int n, cnt = 0;
    while(scanf("%d", &n) && n){
        ps.clear();
        edges.clear();
        for(int i = 0; i < n ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            ps.push_back({a,b});
        }   

       for(int i = 0; i < n ; ++i){
           for(int j = i+1; j < n ; ++j){
               edges.push_back({dist(ps[i], ps[j]),{i,j}});
           }
       }

        go.assign(n, vector<int>());
        kruskal(n);
        memo.assign(n, -1);
        dfs(0);
        printf("Scenario #%d\n", ++cnt);
        printf("Frog Distance = %.3lf\n\n", rec(0));
    }
    return 0;
}