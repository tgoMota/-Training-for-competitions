//https://onlinejudge.org/external/113/11396.pdf
//11396 Claw Decomposition
#include <bits/stdc++.h>
using namespace std;

int main(){

    int V;
    while(scanf("%d", &V) && V){
        int a, b;
        vector<int> adj[V+1];
        while(scanf("%d%d", &a, &b) && a+b){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<int> q;
        bool isBipartite = true;
        vector<int> color(V+1, -1);
        for(int i = 1; i <= V ; ++i){
            if(color[i] != -1) continue;
            q.push(i);
            color[i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int x : adj[u]){
                    if(color[x] == color[u]){
                        isBipartite = false;
                        break;
                    }else if(color[x] == -1){
                        color[x] = 1 - color[u];
                        q.push(x);
                    }
                }
                if(!isBipartite) break;
            }
            if(!isBipartite) break;
        }

        printf("%s\n", isBipartite ? "YES" : "NO");

    }

    return 0;
}