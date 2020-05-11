//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3657
//1216 - The Bug Sensor Problem
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

vector<int> parent;
vector<ii> ps;
vector<pair<double,ii>> edges;

double dist(int i, int j){
    return sqrt(pow(ps[i].first-ps[j].first, 2) + pow(ps[i].second - ps[j].second, 2));
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

int kruskal(int wanted, const int n){
    init(n);
    double cost = 0.0;
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size() ; ++i){
        auto x = edges[i];
        double w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)) continue;
        merge(u, v);
        cost = w;
        if(++wanted == n) break;
    }

    return (int)ceil(cost);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int r;
        scanf("%d", &r);
        int a, b;
        ps.clear();
        edges.clear();
        while(scanf("%d", &a) && a != -1){
            scanf("%d", &b);
            ps.push_back({a,b});
        }

        const int N = ps.size();

        for(int i = 0; i < N ; ++i){
            for(int j = i+1; j < N ; ++j){
                edges.push_back({dist(i,j),{i,j}});
            }
        }

        printf("%d\n", kruskal(r, N));
    }

    return 0;
}