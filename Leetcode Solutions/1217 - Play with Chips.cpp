//https://leetcode.com/problems/play-with-chips/
//1217. Play with Chips
class Solution {
public:
    int minCostToMoveChips(vector<int>& c) {
        int odd = 0, even = 0;
        for(int x : c){
            if(x % 2 == 0) even++;
            else odd++;
        }
        
        return min(even, odd);
    }
};