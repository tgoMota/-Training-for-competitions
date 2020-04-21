//https://www.urionlinejudge.com.br/judge/pt/problems/view/2778
//URI 2778 - Matriz do Dabriel
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int memo[101][101][21][21][2][2];
int vx[] = {1,0,0}, vy[] = {0,-1,1};
int grid[101][101];
bool ok = false;
int solve(int i, int j, int x, int y,bool alreadyWentLeft,bool alreadyWentRight,const int N, const int M){
    if(x < 0 || y < 0 || i < 0 || j < 0 || i >= N || j >= M) return oo;
    if(i == N-1 && j == M-1) {
        ok = true;
        return grid[i][j];
    }
    int& ans = memo[i][j][x][y][alreadyWentLeft][alreadyWentRight];
    if(ans != -1) return ans;
    ans = oo;
    for(int k = 0; k < 3 ; ++k){
        if(k == 1 && alreadyWentRight) continue;
        if(k == 2 && alreadyWentLeft) continue;
        int newi = i + vx[k];
        int newj = j + vy[k];
        int newx = grid[newi][newj] == 0 ? x-1 : x;
        int newy = grid[newi][newj] < 0 ? y-1 : y;
        bool newAlreadyWentLeft = alreadyWentLeft, newAlreadyWentRight = alreadyWentRight;
        if(k == 0) newAlreadyWentLeft = false, newAlreadyWentRight = false;
        if(k == 1) newAlreadyWentLeft = true;
        if(k == 2) newAlreadyWentRight = true;
        ans = min(ans, grid[i][j]+solve(newi, newj, newx, newy,newAlreadyWentLeft,newAlreadyWentRight, N, M));
    }
    return ans;
}
int main(){
    int N, M, X, Y;
    while(scanf("%d%d%d%d", &N, &M, &X, &Y) != EOF){
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < M ; ++j){
                scanf("%d", &grid[i][j]);
            }
        }
        memset(memo, -1, sizeof(memo));
        X = grid[0][0] == 0? X-1 : X;
        Y = grid[0][0] < 0 ? Y-1 : Y;
        ok = false;
        int ans = solve(0,0,X,Y,false,false,N,M);
        if(ok) printf("%d\n", ans);
        else printf("Impossivel\n");
    }
    return 0;
}