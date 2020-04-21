//https://leetcode.com/problems/sum-of-two-integers/
//371. Sum of Two Integers
class Solution {
public:
    // 001 010 (1,2)  => //0101 //0100 = 1001
    int getSum(int a, int b) {
        int carry = (unsigned int)(a&b) << 1;
        int ans = a^b; //no carry
        return carry? getSum(ans, carry) : ans;
    }
};