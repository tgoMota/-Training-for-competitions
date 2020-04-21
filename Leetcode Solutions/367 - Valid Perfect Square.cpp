//https://leetcode.com/problems/valid-perfect-square/
//367. Valid Perfect Square
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long hi = num, lo = 0, mid;
        while(lo <= hi){
            mid = (lo+hi)>>1;
            if(mid*mid == num) return true;
            if(mid*mid <= num) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};
int main(){
    int k;
    cin >> k;
    Solution a;
    printf("%s\n",a.isPerfectSquare(k)? "true":"false" );

    return 0;
}