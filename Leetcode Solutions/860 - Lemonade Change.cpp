//https://leetcode.com/problems/lemonade-change/
//860. Lemonade Change
class Solution {
public:
    int wallet[21];
    bool lemonadeChange(vector<int>& b) {
        for(int i = 0; i < b.size() ; ++i){
            wallet[b[i]]++;
            b[i]-=5;
            while(b[i] > 0){
                if(b[i]>=10 && wallet[10]>0){
                    b[i]-=10;
                    wallet[10]--;
                }else if(wallet[5]>0){
                    b[i]-=5;
                    wallet[5]--;
                }else return false;
            }
        }
        return true;
    }
};