class Solution {
public:
    vector<int> vx = {0,0,0,1,-1}, vy = {0,1,-1,0,0};
    int bfs(int nodex,int nodey, vector<vector<int>>& grid){
        const int R = grid.size();
        const int C = grid[0].size();
        bool vst[R][C];
        memset(vst, false, sizeof(vst));
        
        set<pair<int,pair<int,int>>> p;
        p.insert({0,{nodex,nodey}});
        int ans = 0;
        while(!p.empty()){
            auto next = *p.begin();
            p.erase(p.begin());
            int value = next.first;
            int posx = next.second.first;
            int posy = next.second.second;
            if(vst[posx][posy]) continue;
            vst[posx][posy] = true;
            if(posx == R-1 && posy == C-1) return ans = value;
            for(int i = 1; i <= 4 ; ++i){
                int newx = posx + vx[i];
                int newy = posy + vy[i];
                if(newx < 0 || newy < 0 || newx >= R || newy >= C) continue;
                if(vst[newx][newy]) continue;
                int newValue = (grid[posx][posy] != i)+value;
                p.insert({newValue,{newx, newy}});
            }
        }
        return ans;
    }
    int minCost(vector<vector<int>>& grid) {
        return bfs(0,0,grid);
    }
};