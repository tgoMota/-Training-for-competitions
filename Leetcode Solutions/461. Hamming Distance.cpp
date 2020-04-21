//https://leetcode.com/problems/hamming-distance/
//461. Hamming Distance
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        return __builtin_popcount(ans);
    }
};