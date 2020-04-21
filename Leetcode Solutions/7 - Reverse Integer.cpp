//https://leetcode.com/problems/reverse-integer/
//7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x!=0){
            ans = (ans*10) + (x%10);
            x/=10;
        }
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        else return ans;
    }
};

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