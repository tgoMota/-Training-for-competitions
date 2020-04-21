//http://codeforces.com/contest/3/problem/A
#include <bits/stdc++.h>
using namespace std;

int dist[9][9], ki, kj, si, sj, anti[9][9], antj[9][9];

void bfs(int vi, int vj){
    memset(dist, -1, sizeof(dist));
    dist[vi][vj] = 0;
    queue<pair<int, int> > fila;
    fila.push({vi, vj});
    int auxi, auxj, vx[8] = {1,0,-1,0,1,1,-1,-1}, vy[8] = {0,1,0,-1,1,-1,1,-1};
    while(!fila.empty()){
        auxi = fila.front().first;
        auxj = fila.front().second;
        fila.pop();
        for(int i = 0; i < 8; ++i){
            int posi = vx[i] + auxi, posj = vy[i] + auxj;
            if(posi < 1 || posj < 1 || posi > 8 || posj > 8) continue;
            if(dist[posi][posj] != -1) continue;
            dist[posi][posj] = dist[auxi][auxj] + 1;
            anti[posi][posj] = auxi;
            antj[posi][posj] = auxj;
            fila.push({posi, posj});
        }
    }
}

void printa(int ai, int aj, int bi, int bj){
    if(ai == bi){
        if(bj < aj) cout << "L";
        else cout << "R";
    }else if(aj == bj){
        if(ai < bi) cout << "D";
        else cout << "U";
    }else{
        if(ai < bi && aj < bj) cout << "RD";
        if(ai > bi && aj < bj) cout << "RU";
        if(ai > bi && aj > bj) cout << "LU";
        if(ai < bi && aj > bj) cout << "LD";
    }
    cout << endl;
}

int main()
{
    char cs, ck;
    cin >> cs >> si;
    cin >> ck >> ki;
    si = 9 - si; sj = cs - 96; ki = 9 - ki; kj = ck - 96;
    bfs(ki, kj);

    int posi = si, posj = sj, ai = si;
    cout << dist[si][sj] <<endl;
    while(posi != ki || posj != kj){
       printa(posi, posj, anti[posi][posj], antj[posi][posj]);
       posi = anti[posi][posj];
       posj = antj[ai][posj];
       ai = posi;
    }

    return 0;
}
