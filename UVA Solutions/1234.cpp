//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3675
//UVA 1234 - RACING
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> parent;
vector<pair<int, ii>> edges;

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

int kruskal(const int n){
    init(n);
    int cost = 0;
    sort(edges.begin(), edges.end(), greater<pair<int,ii>>());
    for(int i = 0; i < (int)edges.size(); ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(find(u) == find(v)){
            cost+=w;
            continue;
        }

        merge(u, v);
    }
    return cost;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, k;
        scanf("%d%d", &n, &m);
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            edges.push_back({c,{a,b}});
        }

        printf("%d\n", kruskal(n));
    }
    scanf("%d", &t);
    return 0;
}