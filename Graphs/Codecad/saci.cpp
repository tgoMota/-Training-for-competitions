//http://www.codcad.com/problem/120
#include <bits/stdc++.h>
#define MAX 1020
using namespace std;

int posi,posj, finali, finalj, ans, dist[MAX][MAX], adj[MAX][MAX], vx[4] = {0, 1, 0, -1}, vy[4] = {1, 0, -1, 0};

void dfs(int vi, int vj){
    for(int i = 0; i < 4 ; ++i){
        int ix = vi + vx[i];
        int iy = vj + vy[i];

        if(dist[ix][iy] != -1 || adj[ix][iy] == 0) continue;

        dist[ix][iy] = dist[vi][vj]+ 1;
        dfs(ix, iy);
    }
}

int main(){
    memset(dist, -1, sizeof(dist));
    int n, m, k;
    cin >> n >> m;
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m ; ++j){
            cin >> k;
            if(k == 2){
                posi = i;
                posj = j;
            }
            if(k == 3){
                finali = i;
                finalj = j;
            }
            adj[i][j] = k;
        }
    }
    dist[posi][posj] = 1;
    dfs(posi, posj);

    cout << dist[finali][finalj] << endl;

    return 0;
}
