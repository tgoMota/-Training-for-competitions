//875. Koko Eating Bananas
//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
    int check(int ans, vector<int> p){
        int time = 0;
        for(int i = 0; i < p.size() ; ++i){
            if(p[i] % ans == 0) time += p[i]/ans;
            else time += (p[i]/ans) + 1;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        long long int sum = 0LL;
        for(int i = 0; i < piles.size() ; ++i) sum+= (long long) piles[i];
        long long int hi = sum, lo = 1LL, mid;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(check(mid, piles) > H) lo = mid+1;
            else hi = mid;
        }
        return lo;
    }
};