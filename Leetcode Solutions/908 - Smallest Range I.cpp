//https://leetcode.com/problems/smallest-range-i/
//908. Smallest Range I
class Solution {
public:
    int smallestRangeI(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int minp = a[0], maxp = a.back(), add = 0;
        for(int i = 0; i < a.size() ; ++i){
            add = maxp-a[i];
            if(add > k) add = k;
            a[i]+=add;
            if(i == 0) minp = a[i];
            else minp = min(minp, a[i]);
        }
        add = minp - a.back();
        if(add < -k) add = -k;
        return a.back()+add-a[0];
    }
};