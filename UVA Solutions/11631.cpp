//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2678
//UVA 11631 - Dark roads
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<vector<ii>> adj;
vector<bool> vst;
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
void process(int v){
    vst[v] = true;
    for(auto x : adj[v]){
        if(vst[x.first]) continue;
        pq.push({x.second, x.first});
    }
}

ll prim(int v, const int N){
    vst.assign(N, false);
    process(0);
    ll mst_cost = 0LL;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int u = x.second;
        ll w = x.first;
        if(vst[u]) continue;
        mst_cost+=w;
        process(u);
    }
    return mst_cost;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m){
        adj.assign(n, vector<ii>());
        ll total_cost = 0LL;
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
            total_cost+=c;
        }

        printf("%lld\n", total_cost - prim(0,n));
    }
    return 0;
}