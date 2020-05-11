//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1310
//UVA 10369 - Arctic Network
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<pair<int,ii>> edges;
vector<int> parent;
vector<ii> ps;

int dist(int i, int j){
    return (ps[i].first-ps[j].first)*(ps[i].first-ps[j].first) + 
    (ps[i].second-ps[j].second) * (ps[i].second-ps[j].second);
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

double kruskal(int m, const int n){
    init(n);
    int cnt = 0, w;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size() ; ++i){
        auto x = edges[i];
        int u = x.second.first;
        int v = x.second.second;
        w = x.first;
        if(find(u) == find(v)) continue;
        if(++cnt == n-m) break;
        merge(u,v);
    }
    return sqrt(w);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &m, &n);
        ps.clear();
        for(int i = 0; i < n ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            ps.push_back({a,b});
        }
        edges.clear();
        for(int i = 0; i < n ; ++i){
            for(int j = i+1; j < n ; ++j){
                edges.push_back({dist(i,j),{i,j}});
            }
        }

        printf("%.2lf\n", kruskal(m,n));
    }
    return 0;
}