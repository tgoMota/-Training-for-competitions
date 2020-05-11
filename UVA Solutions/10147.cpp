#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;
vector<ii> town;
vector<int> parent;
vector<pair<int, ii>> edges;

int dist(int i, int j){
    return (town[i].first-town[j].first)*(town[i].first-town[j].first)+
    (town[i].second-town[j].second)*(town[i].second-town[j].second);
}

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

vector<ii> ans;
void kruskal(const int n){
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size() ; ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if(find(u) == find(v)) continue;
        ans.push_back({u,v});
        merge(u,v);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        if(ti != 1) printf("\n");
        int n, m;
        scanf("%d", &n);
        town.clear();
        for(int i = 0; i < n ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            town.push_back({a,b});
        }
        init(n);
        scanf("%d", &m);
        for(int i = 0; i < m ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            merge(--a,--b);
        }
        edges.clear();
        for(int i = 0; i < n ; ++i){
            for(int j = i+1; j < n ; ++j){
                edges.push_back({dist(i,j),{i,j}});
            }
        }
        ans.clear();
        kruskal(n);
        if((int)ans.size()) for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
        else printf("No new highways need\n");
    }
    return 0;
}