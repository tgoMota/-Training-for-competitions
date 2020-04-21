//https://onlinejudge.org/external/5/572.pdf
//572 Oil Deposits
#include <bits/stdc++.h>
using namespace std;

int grid[101][101], r, c;
int dx[] = {1,1,0,-1,-1,-1,0,1}, dy[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int ro, int co, const int c1, const int c2){
    if(ro < 0 || ro >= r || co < 0 || co >= c) return 0;
    if(grid[ro][co] != c1) return 0;
    grid[ro][co] = c2;
    int ans = 1;
    for(int i = 0; i < 8 ; ++i) ans+= floodfill(ro+dx[i], co+dy[i], c1, c2);
    return ans;
}

int main(){

    while(scanf("%d%d", &r, &c) && r+c){
        for(int i = 0; i < r ; ++i){
            string s; cin >> s;
            for(int j = 0; j < c ; ++j) grid[i][j] = (s[j] == '*') ? 0 : 1;
        }
        int ans = 0;
        for(int i = 0; i < r ; ++i)
            for(int j = 0; j < c ; ++j)
                ans += floodfill(i,j,1,0) > 0;

        printf("%d\n", ans);
    }

    return 0;
}