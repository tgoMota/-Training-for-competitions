//https://www.spoj.com/problems/ABCPATH/
#include <bits/stdc++.h>
using namespace std;
const int maxv = 55;

char tab[maxv][maxv];
int dist[maxv][maxv], n, m, max_dist, clk;

void bfs(int vi, int vj){
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> fila;
    fila.push({vi,vj}); 
    dist[vi][vj] = 0;
    int auxi, auxj, vx[8] = {1, 0, -1, 0, -1, 1, -1, 1}, vy[8] = {0, 1, 0, -1, -1, -1, 1, 1};
    while(!fila.empty()){
        auxi = fila.front().first;
        auxj = fila.front().second;
        fila.pop();
        for(int i = 0; i < 8 ; ++i){
            int pi = auxi + vx[i];
            int pj = auxj + vy[i];
            if(pi < 0 || pj < 0 || pi >= n || pj >= m) continue;
            if(!isalpha(tab[pi][pj]) || tab[pi][pj] - tab[auxi][auxj] != 1 || dist[pi][pj] != -1) continue;
            dist[pi][pj] = dist[auxi][auxj] + 1;
            fila.push({pi, pj});
            if(dist[pi][pj] > max_dist) max_dist = dist[pi][pj];
        }
    }
}

int main(){
    while(cin >> n >> m && n != 0 && m != 0){
        max_dist = INT_MIN;
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                cin >> tab[i][j];
            }
        }
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                if(tab[i][j] == 'A' && max_dist == INT_MIN) max_dist = 0;
                if(tab[i][j] == 'A') bfs(i, j);
            }
        }
        if(max_dist < 0) max_dist = -1;
        cout << "Case " << ++clk << ": " << max_dist+1 << endl;
    }
    return 0;
}
