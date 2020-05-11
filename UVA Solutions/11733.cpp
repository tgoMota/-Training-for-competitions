//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2833
//UVA 11733 - Airports
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<vector<ii>> adj;
vector<pair<int,ii>> edges;
vector<int> parent, rnk;

int find(int u){
    if(u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}

void init(const int N){
    parent.resize(N+1);
    rnk.resize(N+1);
    for(int i = 1; i <= N ; ++i) parent[i] = i, rnk[i] = 0;
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if(rnk[x] > rnk[y]) parent[y] = x;
    else parent[x] = y;
    if(rnk[x] == rnk[y]) rnk[y]++;
}

void kruskal(const int N, const int T, const int A){
    init(N);
    sort(edges.begin(), edges.end());
    int mst_cost = 0, cnt = 0;
    for(int i = 0; i < edges.size() ; ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)) continue;
        merge(u,v);
        mst_cost+= w;
        if(++cnt == N-1) break;
    }
    int airports = N-cnt;
    printf("Case #%d: %lld %d\n", T, (ll)(A*airports)+(ll)mst_cost, airports);
}


int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int N, M, A;
        scanf("%d%d%d", &N, &M, &A);
        edges.clear();
        for(int i = 0; i < M ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(c < A) edges.push_back({c,{a,b}});
        }

        kruskal(N, ti, A);
    }
    return 0;
}