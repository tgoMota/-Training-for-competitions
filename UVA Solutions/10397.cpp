//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1338
//UVA 10397 - Connect the Campus
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<pair<int,ii>> edges;
vector<ii> ps;
vector<int> parent;

int dist(int i, int j){
    return (ps[i].first-ps[j].first)*(ps[i].first-ps[j].first) +
           (ps[i].second-ps[j].second)*(ps[i].second-ps[j].second);
}

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


double kruskal(){
    double cost = 0.0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size();  ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(find(u) == find(v)) continue;
        cost+=sqrt(w);
        merge(u,v);
    }
    return cost;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        ps.clear();
        edges.clear();
        for(int i = 0 ; i < n ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            ps.push_back({a, b});
        }
        init(n);
        int m;
        scanf("%d", &m);
        for(int i = 0; i < m ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            merge(--a, --b);
        }

        for(int i = 0; i < n ; ++i){
            for(int j = i+1; j < n ; ++j){
                edges.push_back({dist(i,j),{i,j}});
            }
        }
        printf("%.2lf\n", kruskal());
    }
    return 0;
}