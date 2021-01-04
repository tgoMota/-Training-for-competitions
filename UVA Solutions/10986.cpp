#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<vector<ii>> adj;
vector<int> dist;

void djikstra(int source, const int n){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,source});
    dist.assign(n+1, oo);
    dist[source] = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int v = x.second;
        for(auto a : adj[v]){
            int u = a.first, w = a.second;
            if(dist[v]+w < dist[u]){
                dist[u] = dist[v]+w;
                pq.push({dist[u], u});
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, m, source, sink;
        scanf("%d%d%d%d", &n, &m, &source, &sink);
        adj.assign(n+1, vector<ii>());
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        djikstra(source,n);
        if(dist[sink] < oo) printf("Case #%d: %d\n", ti, dist[sink]);
        else printf("Case #%d: unreachable\n", ti);
    }
    
    return 0;
}