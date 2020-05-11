//https://onlinejudge.org/external/108/10842.pdf
//UVA 10842 Traffic Flow
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<int> parent;
vector<pair<int,ii>> edges;

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

int kruskal(const int n){
    init(n);
    int mincost = oo;
    sort(edges.begin(), edges.end(), greater<pair<int,ii>>());
    for(int i = 0; i < (int)edges.size() ; ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(find(u) == find(v)) continue;
        mincost = min(mincost, w);
        merge(u, v);
    }
    return mincost;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        scanf("%d%d", &n, &m);
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({c, {a, b}});
        }

        printf("Case #%d: %d\n", ti, kruskal(n));
    }
    return 0;
}