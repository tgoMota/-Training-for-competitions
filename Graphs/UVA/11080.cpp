//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2021
//11080 - Place the Guards
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int tc, v, e;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d%d",&v, &e);
        vi adj[v];
        for(int i = 0; i < e ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<int> q;
        vector<int> color(v,-1);
        bool isBipartite = true;
        int ans = 0;
        for(int i = 0; i < v ; ++i){
            if(color[i] != -1) continue;
            int count[2] = {0,0};
            color[i] = 0;
            count[0]++;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int x : adj[u]){
                    if(color[x] == color[u]){
                        isBipartite = false;
                        break;
                    }else if(color[x] == -1){
                        color[x] = 1- color[u];
                        count[color[x]]++;
                        q.push(x);
                    }
                }
                if(!isBipartite) break;
            }
            if(!isBipartite) break;
            ans += max(1, min(count[0], count[1]));
        }

        printf("%d\n", isBipartite? ans : -1);
    }

    return 0;
}