#include <bits/stdc++.h>
using namespace std;
int mt[110][110], vx[] = {0,1,1,1,0,-1,-1,-1}, vy[] = {-1,-1,0,1,1,1,0,-1};
bool vst[110][110];

void dfs(int posi, int posj, const int r, const int c){
    for(int i = 0; i < 8 ; ++i){
        int nx = posj+vx[i], ny = posi+vy[i];
        if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
        if(vst[ny][nx]) continue;
        if(mt[ny][nx] <= 128 || abs(mt[posi][posj] - mt[ny][nx]) > 10) continue;
        vst[ny][nx] = true;
        dfs(ny, nx, r, c);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    memset(vst, false, sizeof(vst));
    for(int i = 0; i < n ; ++i)
        for(int j = 0; j < m ; ++j) scanf("%d", &mt[i][j]);

    int ans = 0;
    for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m ; ++j){
            if(mt[i][j] <= 128 || vst[i][j]) continue;
            ans++;
            vst[i][j] = true;
            dfs(i, j, n, m);
        }
    }

    printf("%d\n", ans);
    
    return 0;
}