//https://leetcode.com/problems/time-needed-to-inform-all-employees/
//1376. Time Needed to Inform All Employees
class Solution {
public:
    vector<vector<int>> adj;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        for(int i = 0; i < n ; ++i) if(i != headID) adj[manager[i]].push_back(i);
        return informAll(headID, informTime);
    }
    
    int informAll(int pos, vector<int>& informTime){
        int sum = 0;
        for(int x : adj[pos]) sum = max(sum,informTime[pos]+informAll(x,informTime));
        return sum;
    }
};