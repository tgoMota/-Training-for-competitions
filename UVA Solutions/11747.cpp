//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=2847&mosmsg=Submission+received+with+ID+24986119
//UVA 11747 Heavy Cycle Edges
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<pair<int,ii>> edges;
vector<int> parent, rnk;

void init(const int N){
    parent.resize(N);
    rnk.resize(N);
    for(int i = 0; i < N ; ++i) rnk[i] = 0, parent[i] = i;
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
    int mst_cost = 0, cycles = 0;
    multiset<int> cyc;
    for(int i = 0; i < edges.size(); ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)){
            cycles++;
            cyc.insert(w);
            continue;
        }
        
        mst_cost+=w;
        merge(u,v);
    }
    if(!cycles) printf("forest\n");
    else{
        for(int x : cyc) {
            printf("%d", x);
            if(--cycles) printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m){
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({c, {a,b}});
        }

        kruskal(n);

    }
    return 0;
}