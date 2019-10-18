//278. First Bad Version
//https://leetcode.com/problems/first-bad-version/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long hi = n, lo = 1LL, mid, ans;
        while(lo<=hi){
            mid = (lo+hi)>>1;
            if(isBadVersion(mid)) ans = mid, hi = mid-1LL;
            else lo = mid+1LL;
        }
        return ans;
    }
};