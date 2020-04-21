//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
//1281. Subtract the Product and Sum of Digits of an Integer
class Solution {
public:
    int subtractProductAndSum(int n) {
        string a = to_string(n);
        int prod = 1, sum = 0;
        for(int i = 0; i < a.size() ; ++i){
            prod*=(a[i]-'0');
            sum+=(a[i]-'0');
        }
        return prod-sum;
    }
};