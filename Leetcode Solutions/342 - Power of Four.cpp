//https://leetcode.com/problems/power-of-four/
//342. Power of Four
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n > 1 && n%4 == 0) n/=4;
        return n == 1;
    }
    //Another solution
    //return n > 0 && (n&(n - 1)) == 0 && (n-1) % 3 == 0;
};