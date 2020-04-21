//https://leetcode.com/problems/find-the-town-judge/
//997. Find the Town Judge
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> adj[N+1];
        for(int i = 0; i < trust.size() ; ++i){
            int a = trust[i][0], b = trust[i][1];
            adj[a].push_back(b);    
        }
        int cont = 0, pos;
        for(int i = 1; i <= N ; ++i){
            if(adj[i].size() == 0) cont++, pos = i;
            if(cont>1) return -1;
        }
        if(!cont) return -1;
        for(int i = 1; i <= N ; ++i){
            if(i == pos) continue;
            bool achou = false;
            for(int x : adj[i]) if(x == pos) achou = true;
            if(!achou) return -1;
        }
        return pos;
    }
};