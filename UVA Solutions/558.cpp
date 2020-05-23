//https://onlinejudge.org/external/5/558.pdf
//UVA 558 Wormholes
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<pair<int, ii>> edges;
vector<int> dist;

bool belmanFord(const int n){
    dist.assign(n, oo);
    dist[0] = 0;
    for(int i = 0; i < n-1 ; ++i){
        for(auto e : edges){
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;

            dist[v] = min(dist[v], dist[u]+w);
        }
    }
    
    for(auto e : edges){
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if(dist[u]+w < dist[v]) return false;
    }
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({c, {a,b}});
        }

        printf("%s\n", !belmanFord(n) ? "possible" : "not possible");
    }
    return 0;
}