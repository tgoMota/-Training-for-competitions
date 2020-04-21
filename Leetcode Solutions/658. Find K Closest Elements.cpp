//https://leetcode.com/problems/find-k-closest-elements/
//658. Find K Closest Elements
class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
       int lo = 0, hi = a.size() - 1;
       while(hi-lo >= k){
           if(abs(a[lo]-x) <= abs(a[hi]-x)) hi--;
           else lo++;
       }
        vector<int> subList(a.begin()+lo, a.begin()+hi+1);
        return subList;
    }
};