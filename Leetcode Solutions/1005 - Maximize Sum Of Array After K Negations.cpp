//https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
//1005. Maximize Sum Of Array After K Negations
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& a, int k) {
        int sum = 0;
        sort(a.begin(), a.end());
        for(int& x : a){
            if(x < 0 && k){
                x = -x;
                k--;
            }
            sum+= x;
        }
        int minx = *min_element(a.begin(), a.end());
        if(k % 2 == 1) sum -= (2*minx);
        return sum;
    }
};