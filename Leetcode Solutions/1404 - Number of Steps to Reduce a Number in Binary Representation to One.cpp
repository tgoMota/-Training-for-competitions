//https://leetcode.com/contest/weekly-contest-183/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
//1404. Number of Steps to Reduce a Number in Binary Representation to One
class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        for(int i = s.size()-1; i >=0 ; --i){
            if(s[i] == '1' && i != 0){
                string antes = s;
                for(int j = i; j >= 0 ; --j){
                    if(s[j] == '0') {
                        s[j] = '1';
                        break;
                    }
                    if(s[j] == '1') s[j] = '0';
                    if(j == 0){
                        s = '1'+s;
                        i++;
                    }
                }
                ans++;
            }
            if(i == 0 && s[i] == '1') break;
            ans++;
        }
        return ans;
    }
};