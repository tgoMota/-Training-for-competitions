//http://www.codcad.com/problem/121
#include <bits/stdc++.h>
using namespace std;

int dist[102][102], n, tab[102][102];

void djisktra(int vi, int vj){
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < n ; ++j){
            dist[i][j] = -1;
        }
    }
    set<pair<int,pair<int,int>> >fila;
    if(tab[vi][vj]) fila.insert({1,{vi,vj}});
    else fila.insert({0,{vi,vj}});
    int vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1}, auxi, auxj;
    pair<int,pair<int,int>> aux;
    while(!fila.empty()){
        aux = *fila.begin();
        fila.erase(fila.begin());
        int auxi = aux.second.first;
        int auxj = aux.second.second;
        int distv = aux.first;
        if(dist[auxi][auxj] != -1) continue;
        dist[auxi][auxj] = distv;
        for(int i = 0; i < 4 ; ++i){
            int vi = vy[i] + auxi;
            int vj = vx[i] + auxj;
            if(vi < 0 || vj < 0 || vi >= n || vj >= n || dist[vi][vj] != -1) continue;
            fila.insert({tab[vi][vj] + distv,{vi,vj}});
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < n ; ++j){
            cin >> tab[i][j];
        }
    }
    djisktra(0,0);
    cout << dist[n-1][n-1] << endl;

    return 0;
}