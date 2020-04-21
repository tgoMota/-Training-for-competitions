//https://leetcode.com/problems/sum-of-square-numbers/
//633. Sum of Square Numbers
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long hi = num, lo = 0LL, mid;
        if(num < 0) return false;
        while(lo <= hi){
            mid = (lo+hi)>>1;
            if(mid*mid == num) return true;
            if(mid*mid <= num) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }

    bool judgeSquareSum(int c) {
        for(int i = 0; i*i <= c ; ++i)
            if(isPerfectSquare(c-(i*i))) return true;
        return false;
    }
};

int main(){
    int k;
    cin >> k;
    Solution a;
    printf("%s\n",a.judgeSquareSum(k)? "true":"false" );

    return 0;
}