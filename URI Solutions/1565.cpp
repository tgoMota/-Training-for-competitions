//https://www.urionlinejudge.com.br/judge/pt/problems/view/1565
//URI 1565 - Ligue os Pontos
//Wrong
// #include <bits/stdc++.h>
// using namespace std;
// #define oo 0x3f3f3f3f

// int memo[101][101][101];
// const int vx[] = {1,1,1,0,-1,-1,-1,0}, vy[] = {-1,0,1,1,1,0,-1,-1};
// int solve(int i, int j, int rest, const int N, const int M, vector<vector<char>>& grid){
//     if(rest == 0) return 0;
//     if(i >= N || j >= M || i < 0 || j < 0) return oo;
//     if(grid[i][j] == '#') return oo;
//     int& ans = memo[i][j][rest];
//     if(ans != -1) return ans;
//     int newRest = grid[i][j] == '*' ? rest-1 : rest;
//     ans = oo;
//     for(int d = 0; d < 8 ; ++d){
//         int x = vx[d] + i;
//         int y = vy[d] + j;
//         if(x < 0 || y < 0 || x >= N || y >= M) continue;
//         ans = min(ans, solve(x,y,newRest, N, M, grid) + 1);
//     }
//     return ans;
// }

// int main(){
//     int N, M;
//     while(scanf("%d%d", &N, &M) != EOF){
//         int cnt = 0, posi = -1, posj = -1;
//         vector<vector<char>> grid(N, vector<char>(M));
//         for(int i = 0; i < N ; ++i){
//             for(int j = 0; j < M ; ++j) {
//                 scanf("%c", &grid[i][j]);
//                 if(grid[i][j] == '*') cnt++, posi = i, posj = j;
//             }
//         }

//         memset(memo, -1, sizeof(memo));
//         int ans = solve(posi,posj,cnt,N,M, grid);
//         if(ans >= 0) printf("%d\n", ans);
//         else printf("impossivel\n");
//     }
//     return 0;
// }