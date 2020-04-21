//https://leetcode.com/problems/ugly-number/
//263. Ugly Number
class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;
        int v[] = {2,3,5};
        for(int i = 0; i < 3 ; ++i){
            while(num % v[i] == 0) num/=v[i];
            if(num == 1) return true;
        }
        return false;
    }
};