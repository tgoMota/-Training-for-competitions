//https://leetcode.com/problems/check-if-n-and-its-double-exist/
//1346. Check If N and Its Double Exist
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int ans = 0;
        for(int i = 0; i < arr.size() ; ++i){
            for(int j = 0; j < arr.size() ; ++j){
                if(i == j) continue;
                if(arr[j] == 2*arr[i]) return true;
            }
        }
        return false;
    }
};