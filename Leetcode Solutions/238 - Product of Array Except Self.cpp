class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        int mult = 1, qtdzeros = 0;
        for(int x : nums){
            if(x == 0) qtdzeros++;
            else mult*=x;
        }
        vector<int> ans(N);
        for(int i = 0; i < N ; ++i) {
            if(nums[i] == 0) ans[i] = qtdzeros > 1 ? 0 : mult;
            else ans[i] = qtdzeros ? 0 : mult/nums[i];
        }
        return ans;
    }
};