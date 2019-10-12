#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long long hi = x,lo = 0, mid, ans;
        while(lo<=hi){
            mid = (lo+hi) >> 1;
            if(mid*mid <= x) ans = mid, lo = mid+1LL;
            else hi = mid-1LL;
        } 
        return ans;
    }
};
int main(){
    int k;
    cin >> k;
    Solution a;
    printf("%d\n", a.mySqrt(k));

    return 0;
}