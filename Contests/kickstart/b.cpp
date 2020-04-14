#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

const int mi = 3005;
int memo[55][55][mi];

int solve(int st, int col, int r ,const int K, const int N, vector<vector<int>>& sta){
    if(r == 0) return 0;
    if(col == K) return solve(st+1, 0, r, K, N, sta); 
    if(st == N) return -oo;
    int& ans = memo[st][col][r];
    if(ans != -1) return ans;
    return ans = max(sta[st][col] + solve(st, col+1, r-1, K, N, sta), solve(st+1, 0,r,K,N, sta));
}

int main(){
    int t, n, k, p;
    vector<vector<int>> sta;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d%d%d", &n, &k, &p);
        sta.assign(n, vector<int>(k));
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < k ; ++j){
                scanf("%d", &sta[i][j]);
            }
        }
        memset(memo, -1, sizeof(memo));
        printf("Case #%d: %d\n", ti, solve(0,0,p,k,n, sta));
        for(int i = 0; i < n ; ++i) sta[i].clear();
    }

    return 0;
}