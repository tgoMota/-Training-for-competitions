class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        const int N = g.size();
        vector<vector<int>> adj(N+1);
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < g[i].size() ; ++j){
                int a = i, b = g[i][j];
                adj[a].push_back(b);
            }
        }
        
        vector<int> color(N+1, -1);
        for(int i = 0; i < N ; ++i){
            if(color[i] != -1) continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int thisNode = q.front();
                q.pop();
                for(int nextNode : adj[thisNode]){
                    if(color[thisNode] == color[nextNode]) return false;
                    else if(color[nextNode] == -1) {
                        color[nextNode] = 1-color[thisNode];
                        q.push(nextNode);
                    }
                }
            }
        }
        return true;
    }
};