//https://leetcode.com/problems/target-sum/
//494. Target Sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        
    long int memo[23][2010];
    long int pd(int sum, int i, vector<int>& nums, int S){
        if(sum == S && i == nums.size()) return 1;
        if(i == nums.size()) return 0;
        long int& ans = memo[i][sum+1000];
        if(ans != -1) return ans;
        return ans = pd(nums[i] + sum, i+1, nums, S) + pd(sum - nums[i], i+1, nums, S);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(memo, -1, sizeof(memo)); 
        return pd(0,0,nums,S);
    }

};

int main(){
    vector<int> v = {1,1,1,1,1};
    Solution *a = new Solution();
    cout << a->findTargetSumWays(v,3) << endl;
    return 0;
}