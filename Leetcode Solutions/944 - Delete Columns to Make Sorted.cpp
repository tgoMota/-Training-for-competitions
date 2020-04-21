//https://leetcode.com/problems/delete-columns-to-make-sorted/
//944. Delete Columns to Make Sorted
class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int ans = 0;
        for(int i = 0; i < a[0].size() ; ++i){
            for(int j = 0; j < a.size()-1;  ++j){
                if(a[j][i] > a[j+1][i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};