//UVA 11710 - Expensive subway
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> station;
typedef pair<int,int> ii;
priority_queue<ii, vector<ii> , greater<ii>> pq;
vector<vector<ii>> adj;
vector<bool> vst;
int n, m;

void process(int v){
    vst[v] = true;
    for(auto x : adj[v]){
        if(vst[x.first]) continue;
        pq.push({x.second, x.first});
    }
}

int prim(int v){
    vst.assign(n, false);
    process(v);
    int mst_cost = 0, cnt = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int u = x.second;
        int w = x.first;
        if(vst[u]) continue;
        mst_cost += w;
        process(u);
        cnt++;
    }

    return cnt == n-1 ? mst_cost : -1;
}

int main(){
    char stat1[12], stat2[12];
    int c;
    while(scanf("%d%d", &n, &m) && n+m){
        station.clear();
        for(int i = 0; i < n ; ++i){
            scanf("%s", &stat1);
            station[string(stat1)] = i;
        }
        adj.assign(n, vector<pair<int,int>>());
        for(int i = 0; i < m; ++i){
            scanf("%s%s%d", &stat1, &stat2, &c);
            int u = station[string(stat1)];
            int v = station[string(stat2)];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        scanf("%s", &stat1);
        int cost = prim(station[string(stat1)]);
        if(cost == -1) printf("Impossible\n");
        else printf("%d\n", cost);

    }
    return 0;
}