//http://codeforces.com/problemset/problem/20/C
//C. Dijkstra? || Codeforces
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100010];
int n, m, dist[100010], ant[100010];

void djikstra(int v){
    for(int i = 1; i <=n ; ++i) {dist[i] = -1, ant[i] = -1;}
    set<pair<int,pair<int,int>>> fila;
    fila.insert({0,{v,-1}});
    pair<int,pair<int,int>> aux;
    while(!fila.empty()){
        aux = *fila.begin();
        fila.erase(fila.begin());
        int distv = aux.first, ver = aux.second.first;
        if(dist[ver] != -1) continue;
        dist[ver] = distv;
        ant[ver] = aux.second.second;
        for(auto vis : adj[ver]){
            if(dist[vis.first] != -1) continue;
            fila.insert({distv + vis.second, {vis.first,ver}});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m ; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    bool vst[n+1];
    djikstra(n);
    if(dist[1] == -1){
        cout << -1 << endl;
        return 0;  
    }
    int prox = 1;
    cout << prox << " ";
    memset(vst, false, sizeof(vst));
    while(prox != n && !vst[prox]){
        cout << ant[prox] << " ";
        vst[prox] = true;
        prox = ant[prox];
    }
    cout << endl;
    return 0;
}