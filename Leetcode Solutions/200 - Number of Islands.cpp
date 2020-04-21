int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
class Solution {
public:
    int dfs(int idx,int idy, vector<vector<char>>& grid){
        if(grid[idx][idy] == '0') return 0;
        grid[idx][idy] = '0';
        for(int i = 0; i < 4 ; ++i){
            int x = idx+dx[i];
            int y = idy+dy[i];
            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;
            dfs(x,y,grid);
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size();  ++i){
            for(int j = 0; j < grid[0].size() ; ++j){
                ans+=dfs(i,j,grid);
            }
        }
        return ans;
    }
};