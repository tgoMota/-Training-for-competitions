#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
const int mod = 1e9+7;
vector<vector<int>> grid;
int main(){

    int r, c;
    cin >> r >> c;
    grid.assign(r+1, vector<int>(c+1, 1));
    for(int i = 1; i <= r ; ++i){
        for(int j = 1; j <= c ; ++j){
            char ch;
            cin >> ch;
            if(ch == '#') grid[i][j] = 0;
        }
    }
    vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
    int dx[]={1,0}, dy[]={0,1};
    dp[1][1] = 1;
    for(int i = 1; i <= r ; ++i){
        for(int j = 1; j<= c ; ++j){
            for(int k = 0; k < 2 ; ++k){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx < 1 || ny < 1 || nx > r || ny > c) continue;
                if(!grid[nx][ny]) continue;
                dp[nx][ny] = (dp[nx][ny]+dp[i][j])%mod;
            }
        }
    }
    printf("%d\n", dp[r][c]);

    return 0;
}