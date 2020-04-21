//https://leetcode.com/problems/power-of-two/
//231. Power of Two
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcountl(n) == 1;
    }
};