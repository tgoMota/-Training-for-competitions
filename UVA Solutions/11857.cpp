//UVA 11857 - Driving Range
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2957
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<pair<int, ii>> edges;
vector<int> parent, rnk;

void init(const int N){
    parent.resize(N);
    rnk.resize(N);
    for(int i = 0; i < N ; ++i) parent[i] = i, rnk[i] = 0;
}

int find(int u){
    if(u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if(rnk[x] > rnk[y]) parent[y] = x;
    else parent[x] = y;
    if(rnk[x] == rnk[y]) rnk[y]++;
}


void kruskal(const int N){
    init(N);
    sort(edges.begin(), edges.end());
    int maxrange = 0, cnt = 0;
    for(int i = 0; i < edges.size(); ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(find(u) == find(v)) continue;
        maxrange = max(maxrange, w);
        merge(u,v);
        if(++cnt == N-1) break;
    }
    if(cnt == N-1) printf("%d\n", maxrange);
    else printf("IMPOSSIBLE\n");
}


int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m){
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({c,{a,b}});
        }

        kruskal(n);
    }
    return 0;
}