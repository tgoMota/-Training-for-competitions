//https://leetcode.com/problems/single-number-ii/
//137. Single Number II
class Solution {
public:
    int singleNumber(vector<int>& a) {
        int bits[32], ans = 0;
        memset(bits, 0, sizeof(bits));
        for(int i = 0; i < a.size() ; ++i){
            for(int j = 0; j < 32 ; ++j){
                if(a[i] & (1<<j)) bits[j]++;
            }
        }
        
        for(int i = 0; i < 32 ; ++i){
            if(bits[i] == 0) continue;
            if(bits[i] % 3) ans+=1<<i;
        }
        
        return ans;
    }
};