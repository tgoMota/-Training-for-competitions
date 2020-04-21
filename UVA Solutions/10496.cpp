#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int dist[21][21];
int memo[1<<11][11];

int solve(int mask, int pos, const int& n){
    if(mask == 0) return pos == 0? 0:oo;
    int& ans = memo[mask][pos];
    if(ans != -1) return ans;
    ans = oo;
    for(int i = 0; i <= n ; ++i){
         if((mask & (1 << i)) == 0) continue;
         ans = min(ans, dist[i][pos] + solve(mask - (1 << i), i, n));
    }
    return ans;
}


int main(){

    int nc, x[21], y[21], sx, sy, c;
    scanf("%d", &nc);
    while(nc--){
        scanf("%d%d", &sx, &sy);
        scanf("%d%d", &x[0], &y[0]);
        scanf("%d", &c);
        for(int i = 1; i <= c ; ++i) scanf("%d%d", &x[i], &y[i]);
        
        for(int i = 0; i <= c ; ++i)
            for(int j = 0; j <= c ; ++j)
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        
        memset(memo, -1, sizeof(memo));
        printf("The shortest path has length %d\n", solve((1<<(c+1))-1,0,c));
    }

    return 0;
}