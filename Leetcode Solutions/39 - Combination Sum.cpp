//https://leetcode.com/problems/combination-sum/
//39. Combination Sum
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        const int N = candidates.size();
        vector<vector<vector<int>>> dp(target+1, vector<vector<int>>());
        dp[0].push_back(vector<int>());
        for(int j = 0; j < N ; ++j){
            for(int i = candidates[j]; i <= target ; ++i){
                auto v = dp[i-candidates[j]];
                if(v.size() == 0) continue;
                for(auto &x : v) x.push_back(candidates[j]);
                dp[i].insert(dp[i].end(), v.begin(), v.end());
            }
        }
        return dp[target];
    }
};