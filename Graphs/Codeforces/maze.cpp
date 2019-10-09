//http://codeforces.com/contest/377/problem/A
#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int tab[MAX][MAX], dist[MAX][MAX], vx[4] = {0,1,0,-1}, vy[4] = {1,0,-1,0}, maxn, maxm, k;

void dfs(int vi, int vj){
    for(int i = 0; i < 4 ; ++i){
        int ix = vi + vx[i];
        int iy = vj + vy[i];
        if(ix < 0 || iy < 0 || ix > maxn || iy > maxm) continue;
        if(dist[ix][iy] != -1 || tab[ix][iy] != 1) continue;

        dist[ix][iy] = dist[vi][vj] + 1;
        dfs(ix, iy);
        if(k-->0) tab[ix][iy] = 3;
    }

}

void printa(){
    for(int i = 1; i <= maxn ; ++i){
        for(int j = 1; j<= maxm ; ++j){
            if(tab[i][j] == 1)
                cout << ".";
            else if(tab[i][j] == 3)
                cout <<  "X";
            else if(tab[i][j] == 2)
                cout << "#";
        }
        cout << endl;
    }
}

int main(){

    cin >> maxn >> maxm >> k;
    char t;
    memset(dist, -1, sizeof(dist));
    for(int i = 1; i <= maxn ; ++i){
        for(int j = 1; j <= maxm ; ++j){
            cin >> t;
            if(t == '#')
                tab[i][j] = 2;
            else{
                tab[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < maxn ; ++i){
        for(int j = 0; j < maxm ; ++j){
            dfs(i, j);
            if(k <= 0) break;
            
        }
        if(k <= 0) break;
    }
    printa();

    return 0;
}