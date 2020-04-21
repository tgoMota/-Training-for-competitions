//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
//1351. Count Negative Numbers in a Sorted Matrix
class Solution {
public:
    int bs(vector<int>& v){ 
        int lo = 0, hi = v.size()-1, mid;
        if(v[hi] >= 0) return 0;
        if(v[0] < 0) return v.size();
        while(lo< hi){
            mid = (lo+hi)/2;
            if(v[mid] < 0) hi = mid;
            if(v[mid] >= 0) lo = mid+1;
        }
        return v.size()-lo;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; ++i) ans+=bs(grid[i]);
        return ans;
    }
};