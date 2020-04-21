class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        int max_len = 0, cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt += nums[i] == 1 ? 1 : -1;
            if (cnt == 0) max_len = i+1;
            else if (freq.find(cnt) != freq.end()) max_len = max(max_len, i - freq[cnt]);
            else freq[cnt] = i;
        }
        
        return max_len;
    }
};