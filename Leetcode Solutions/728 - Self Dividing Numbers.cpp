//https://leetcode.com/problems/self-dividing-numbers/
//728. Self Dividing Numbers
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        bool ehDiv = true;
        for(int i = left; i <= right ; ++i){
            int x = i, r = 0;
            ehDiv = true;
            while(x != 0){
                r = x % 10;
                x/=10;
                if(r == 0 || i % r) {
                    ehDiv = false;
                    break;
                }
            }
            if(ehDiv) ans.push_back(i);
        }
        return ans;
    }
};