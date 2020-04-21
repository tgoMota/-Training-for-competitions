//https://leetcode.com/problems/guess-number-higher-or-lower/submissions/
//374. Guess Number Higher or Lower

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long hi = n, lo = 1LL, mid;
        while(lo<hi){
            mid = (lo+hi)>>1;
            if(guess(mid) == 0) return mid;
            if(guess(mid) == 1) lo = mid+1LL;
            else hi = mid-1LL;
        }
        return lo;
    }
};