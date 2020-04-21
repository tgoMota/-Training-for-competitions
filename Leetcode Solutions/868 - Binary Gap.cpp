//https://leetcode.com/problems/binary-gap/
//868. Binary Gap
class Solution {
public:
    int binaryGap(int n) {
        int last = -1, dist = 0;
        for(int i = 0; i < 32 ; ++i){
            if(n & (1<<i)) {
                if(last != -1) dist = max(dist, i-last);
                last = i;
            }
        }
        return dist;
    }
};