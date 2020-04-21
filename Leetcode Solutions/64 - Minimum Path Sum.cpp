//Djikstra Solution
int vx[] = {0,1}, vy[] = {1,0};
class Solution {
public:
    int djikstra(int i,int j, vector<vector<int>>& grid){
        set<pair<int,pair<int,int>>> s;
        s.insert({grid[i][j],{i,j}});
        vector<vector<bool>> vst(grid.size(), vector<bool>(grid[0].size(), false));
        const int R = grid.size();
        const int C = grid[0].size();
        while(!s.empty()){
            auto x = *s.begin();
            s.erase(s.begin());
            int distx = x.first;
            int xi = x.second.first;
            int yi = x.second.second;
            if(xi == R-1 && yi == C-1) return distx;
            vst[xi][yi] = true;
            for(int i = 0; i < 2 ; ++i){
                int newx = xi+vx[i], newy = yi+vy[i];
                if(newx < 0 || newy < 0 || newx >= R || newy >= C) continue;
                if(vst[newx][newy]) continue;
                s.insert({distx + grid[newx][newy],{newx,newy}});
            }
        }
        return -1;
    }
    int minPathSum(vector<vector<int>>& grid) {
        if((int)grid.size() == 0 || (int)grid[0].size() == 0) return 0;
        return djikstra(0,0,grid);
    }
};

//DP Bottom-UP Solution
#define oo 0x3f3f3f3f
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int r = grid.size(), c = grid[0].size();
        int dx[] = {1,0}, dy[] = {0,1};
        vector<vector<int>>dp(r+1, vector<int>(c+1, oo));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < r ; ++i){
            for(int j = 0; j < c ; ++j){
                for(int k = 0; k < 2 ; ++k){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    dp[nx][ny] = min(dp[i][j]+grid[nx][ny], dp[nx][ny]);
                }
            }
        }
        return dp[r-1][c-1];
    }
};