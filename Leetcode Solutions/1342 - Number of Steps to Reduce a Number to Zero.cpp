//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
//1342. Number of Steps to Reduce a Number to Zero
class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num){
            if(num%2==0) num/=2;
            else --num;
            ans++;
        }
        return ans;
    }
};