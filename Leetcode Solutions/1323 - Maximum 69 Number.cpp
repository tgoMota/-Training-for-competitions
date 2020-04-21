//https://leetcode.com/problems/maximum-69-number/
//1323. Maximum 69 Number
class Solution {
public:
    int maximum69Number (int num) {
        string a = to_string(num);
        int sz = a.size(), ans = 0, swaped = 0;
        for(int i = 0; i < sz ; ++i){
            if(!swaped && a[i] == '6') {
                a[i] = '9';
                swaped = 1;
            }
            ans += (pow(10, sz-i-1)*(a[i]-'0'));
        }
        return ans;
    }
};