//https://leetcode.com/contest/weekly-contest-182/problems/count-number-of-teams/
//1395. Count Number of Teams
const int m = 1e5+5;
class Solution {
public:
    int numTeams(vector<int>& r) {
        int ans = 0;
        for(int i = 0; i < r.size() ; ++i){
            for(int j = i+1; j < r.size() ; ++j){
                if(r[j] < r[i]) continue;
                for(int k = j+1; k < r.size() ; ++k){
                    if(r[k] > r[j]){
                        ans++;
                    }
                }
            }
        }
        
        for(int i = 0; i < r.size() ; ++i){
            for(int j = i+1; j < r.size() ; ++j){
                if(r[j] > r[i]) continue;
                for(int k = j+1; k < r.size() ; ++k){
                    if(r[k] < r[j]){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};