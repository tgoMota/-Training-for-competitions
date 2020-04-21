//https://leetcode.com/problems/walking-robot-simulation/
//874. Walking Robot Simulation
int vy[] = {1,0,-1,0}, vx[] = {0,1,0,-1};
class Solution {
public:
    int distance(int posx, int posy){
        return posx*posx + posy*posy;
    }
    int robotSim(vector<int>& c, vector<vector<int>>& obs) {
        map<pair<int,int>, int> m;
        for(auto x : obs) m[{x[0],x[1]}] = 1;
        int dir = 0, posx = 0, posy = 0, mxdistance = 0, nobs = obs.size();
        for(int i = 0; i < c.size() ; ++i){
            if(c[i] == -1){
                dir = (dir+1)%4;
            }else if(c[i] == -2){
                dir = (dir+3)%4;
            }else{
                for(int j = 0; j < c[i] ; ++j){
                    int newx = posx+vx[dir], newy = posy+vy[dir];
                    int k = m[{newx,newy}];
                    if(k) break;
                    posx = newx, posy = newy;
                    mxdistance = max(mxdistance,distance(posx,posy));
                }
            }
        }
        return mxdistance;
    }
};