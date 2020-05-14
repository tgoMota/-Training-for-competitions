//https://onlinejudge.org/external/113/11396.pdf
//11396 Claw Decomposition
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

bool isBipartite(const int n){
    vector<int> color(n+1, -1);
    queue<int> q;
    for(int v = 1; v <= n ; ++v){
        if(color[v] != -1) continue;
        color[v] = 1;
        q.push(v);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int x : adj[u]){
                if(color[x] == color[u]) return false;
                if(color[x] != -1) continue;
                color[x] = 1-color[u];
                q.push(x);
            }
        }
    }
    return true;
}  

int main(){
    int n;
    while(scanf("%d", &n) && n){
        int a, b;
        adj.assign(n+1, vector<int>());
        while(scanf("%d%d", &a, &b) && a+b){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        printf("%s\n", isBipartite(n) ? "YES" : "NO");
    }
    return 0;
}