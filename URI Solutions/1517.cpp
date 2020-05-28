//https://www.urionlinejudge.com.br/judge/pt/problems/view/1517
//URI 1517 Maçãs
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "passou aqui " << x << endl
#define debug2(x,y) cout << "passou aqui {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int maxN = 1005;
int N, M, K, maxT;
bool grid[21][21][2*maxN];
int dp[21][21][2*maxN];
int dx[] = {0,1, 1, 1, 0, -1, -1, -1, 0}, dy[] = {0,-1, 0, 1, 1, 1, 0, -1, -1};
int solve(int x, int y, int t){
    if(t > maxT || x < 1 || x > N || y < 1 || y > M) return 0;
    int& ans = dp[x][y][t];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 0; i < 9 ; ++i){
        int px = x + dx[i];
        int py = y + dy[i];
        if(px < 1 || px > N || py < 1 || py > M) continue;
        ans = max(ans, grid[x][y][t]+solve(px, py, t+1));
    }
    return ans;
}

int main(){
    while(scanf("%d%d%d", &N, &M, &K) && N+M+K){
        memset(dp, -1, sizeof(dp));
        memset(grid, false, sizeof(grid));
        maxT = 0;
        for(int i = 0; i < K ; ++i){
            int x, y, t;
            scanf("%d%d%d", &x, &y, &t);
            maxT = max(maxT, t);
            grid[x][y][t] = true;
        }
        int PX, PY;
        scanf("%d%d", &PX, &PY);
        printf("%d\n", solve(PX, PY, 0));
    }

    return 0;
}