//https://leetcode.com/problems/happy-number/
//202. Happy Number
typedef long long ll;
class Solution {
public:
    unordered_map<int,int> vst;
    bool isHappy(int n) {
        if(vst.find(n) != vst.end()) return false;
        vst[n] = 1;
        string a = to_string(n);
        int sum = 0;
        for(int i = 0; i < a.length() ; ++i) sum += pow(a[i]-'0', 2);
        return sum == 1 ? true : isHappy(sum);
    }
};