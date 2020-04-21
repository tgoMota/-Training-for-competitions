//https://leetcode.com/problems/friend-circles/
//547. Friend Circles
class Solution {
public:
    vector<int> id;
    int find(int x){
        if(id[x] != x) return find(id[x]);
        return x;
    }
    void unionS(int a, int b){
        int x = find(a), y = find(b);
        if(x != y) id[y] = x;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        for(int i = 0; i < N ; ++i) id.push_back(i);
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < N ; ++j){
                if(M[i][j] == 1) unionS(i,j);
            }
        }
        int ans = 0;
        for(int i  =0; i < N ; ++i)
            if(find(i) == i) ans++;
        return ans;
    }
};