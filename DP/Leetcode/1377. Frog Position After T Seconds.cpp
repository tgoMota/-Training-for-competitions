//https://leetcode.com/problems/frog-position-after-t-seconds/
//1377. Frog Position After T Seconds
class Solution {
public:
    vector<vector<int>> adj;
    int memo[105][55];
    vector<int> way;
    
    int solve(int pos, int time, const int n, const int t, const int target){
        if(time == t || adj[pos].size() == 0) return pos == target;
        int& ans = memo[pos][time];
        if(ans != -1) return ans;
        ans = 0;
        for(int &x : adj[pos]) ans+= solve(x,time+1,n,t,target);
        return ans;
    }
    
    void recover(int pos, int time, const int n, const int t, const int target){
        for(int &x : adj[pos]){
            if(solve(x,time+1,n,t,target)) {
                way.push_back(pos);
                recover(x,time+1,n,t,target);
                break;
            }
        }
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        adj.resize(n+1);
        for(auto x : edges){
            int a = x[0], b = x[1];
            if(a > b) swap(a,b);
            adj[a].push_back(b);
        }
        memset(memo, -1, sizeof(memo));
        int ways = solve(1,0,n,t,target);
        recover(1,0,n,t,target);
        double ans = 1.0;
        for(int x : way) ans *= ((double)1/adj[x].size());
        return ways? ans : 0;
    }
};