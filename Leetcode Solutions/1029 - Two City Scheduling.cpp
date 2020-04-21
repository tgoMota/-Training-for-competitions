//https://leetcode.com/problems/two-city-scheduling/
//1029. Two City Scheduling
class Solution {
public:
    const int oo = 0x3f3f3f3f;
    int memo[102][102];
    
    int solve(int pos,int a, int b, vector<vector<int>>& c, const int N){
        if(pos == N || a>N/2 || b>N/2) return a==b? 0:oo;
        int& ans = memo[pos][b];
        if(ans != -1) return ans;
        return ans = min(c[pos][0]+solve(pos+1, a+1, b, c, N),c[pos][1]+solve(pos+1, a, b+1, c, N));
    }
    
    int twoCitySchedCost(vector<vector<int>>& c) {
        memset(memo, -1, sizeof(memo));
        return solve(0,0,0,c, c.size());
    }
};