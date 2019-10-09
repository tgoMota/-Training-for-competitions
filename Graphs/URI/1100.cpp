//https://www.urionlinejudge.com.br/judge/pt/problems/view/1100
#include <bits/stdc++.h>
using namespace std;

int oi,oj, di, dj, n, dist[9][9];

void bfs(){
    for(int i = 1; i <= 8 ; ++i)
        for(int j = 1; j <= 8 ; ++j)
            dist[i][j] = -1;
    dist[oi][oj] = 0;
    queue<pair<int,int> > fila;
    fila.push({oi,oj});
    int auxi, auxj, vx[8] = {1,1,-1,-1,2,2,-2,-2}, vy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    while(!fila.empty()){
        auxi = fila.front().first;
        auxj = fila.front().second;
        fila.pop();
        for(int i = 0 ; i < 8 ; ++i){
            int vi = vy[i] + auxi, vj = vx[i] + auxj;
            if(vi < 1 || vj < 1 || vi > 8 || vj > 8 || dist[vi][vj] != -1) continue;
            dist[vi][vj] = dist[auxi][auxj] + 1;
            fila.push({vi,vj});
        }
    }
}

int main(){
    char c1, c2;
    while(scanf("%c%d%c%c%d", &c1, &oj,&c2 ,&c2, &dj) != EOF){
        oi = c1 - 96; di = c2 - 96; oj = 9 - oj; dj = 9 - dj;
        bfs();
        cout << "To get from " << c1 << (oj-9)*-1 << " to " << c2 << (dj-9)*-1 << " takes " << dist[di][dj] << " knight moves.\n";
        scanf("%c", &c1);
    }

return 0;
}
