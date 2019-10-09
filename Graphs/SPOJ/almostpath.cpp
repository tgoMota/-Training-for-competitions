//Wrong Answer !!!!!!!
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
const int mx = 505;
typedef pair<int,int> pii;
typedef pair<int,pii> ppi;
vector<pii> adj[mx];
int n, m, o, d, a, b, c, dist[mx], previous[mx];
bool belongs[mx];

void djikstra(int v){
    for(int i = 0 ; i < n ; ++i) dist[i] = -1;
    set<ppi> fila;
    fila.insert({0,{v,-1}}); //{dist,ver,previous}
    ppi aux;
    while(!fila.empty()){
        aux = *fila.begin();
        fila.erase(fila.begin());
        int distV = aux.first, ver = aux.second.first, prev = aux.second.second;
        if(dist[ver] != -1 || !belongs[ver]) continue;
        dist[ver] = distV;
        previous[ver] = prev;
        for(auto x: adj[ver]){
            if(dist[x.first] != -1 || !belongs[x.first]) continue;
            fila.insert({distV+x.second, {x.first, ver}});
        }
    }
}

int main(){
    while(cin >> n >> m && n+m){
        cin >> o >> d;
        for(int i = 0; i < m ; ++i){
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
        }
        memset(belongs, true, sizeof(belongs));
        djikstra(o);
        int bestd = dist[d]; // best distance
        for(auto it = adj[o].begin(); it != adj[o].end() ; ++it){
            if((*it).first == d && bestd == (*it).second) adj[o].erase(it);
        }
        while(dist[d] == bestd){
            int prox = d;
            while(previous[prox] != o){
                belongs[previous[prox]] = false; //delete node
                prox = previous[prox];
            }
            djikstra(o);
        }
        printf("%d\n", dist[d]);
        for(int i = 0; i < mx ; ++i) adj[i].clear();
    }
    return 0;
}
