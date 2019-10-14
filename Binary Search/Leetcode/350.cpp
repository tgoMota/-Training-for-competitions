//https://leetcode.com/problems/intersection-of-two-arrays-ii/
//350. Intersection of Two Arrays II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i, j;
        vector<int> ans;
        for(i = 0, j = 0; i < nums2.size() ; ++i){
            while(j < nums1.size() && nums1[j] < nums2[i]) j++;
            if(j == nums1.size()) break;
            if(nums1[j] != nums2[i]) continue;
            ans.push_back(nums1[j]);
            ++j;
        }
        return ans;
    }
};