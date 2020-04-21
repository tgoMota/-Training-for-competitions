//https://leetcode.com/problems/minimum-falling-path-sum/
//931. Minimum Falling Path Sum
class Solution {
public:
    const int oo = 0x3f3f3f3f;
    int memo[103][103];
    int minFallingPathSum(vector<vector<int>>& A) {
        memset(memo, -1, sizeof(memo));
        int ans = dp(0,-1,A);
        return ans >= oo ? 0 : ans;
    }
    int dp(int i,int j,vector<vector<int>>& A){
        if(i >= A.size()) return 0;
        int& ans = memo[i][j+1];
        if(ans != -1) return ans;
        ans = oo;
        for(int ind = 0; ind < A[i].size() ; ++ind)
            if(j == -1 || abs(ind-j)<=1) ans = min(ans,dp(i+1,ind,A)+A[i][ind]);
        return ans;
    }
};