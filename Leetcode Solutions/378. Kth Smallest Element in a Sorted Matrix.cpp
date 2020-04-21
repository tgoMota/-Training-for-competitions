//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
//378. Kth Smallest Element in a Sorted Matrix
class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        vector<int> ans;
        for(int i = 0; i < m.size() ; ++i)
            for(int j = 0; j < m[0].size() ; ++j)
                ans.push_back(m[i][j]);
            
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};