//https://www.urionlinejudge.com.br/judge/pt/problems/view/1148
//URI 1148 Países em Guerra
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> ii;
vector<vector<ii>> adj;

bool findAndChange(vector<ii>& a, int u){
    for(auto& x : a) if(x.first == u){
        x.second = 0;
        return true;
    }
    return false;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m){
        adj.assign(n+1, vector<ii>());
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(findAndChange(adj[b], a)) c = 0;
            adj[a].push_back({b,c});
        }

        int q;
        scanf("%d", &q);
        vector<int> dist;
        while(q--){
            int o, d;
            scanf("%d%d", &o, &d);
            set<ii> s;
            s.insert({0,o});
            dist.assign(n+1, -1);
            while(!s.empty()){
                auto x = *s.begin();
                s.erase(s.begin());
                int w = x.first;
                int u = x.second;
                if(dist[u] != -1) continue;
                dist[u] = w;
                for(auto v : adj[u]){
                    if(dist[v.first] != -1) continue;
                    s.insert({w+v.second, v.first});
                }
            }
            if(dist[d] != -1) printf("%d\n", dist[d]);
            else printf("Nao e possivel entregar a carta\n");
        }
        printf("\n");
    }
    return 0;
}