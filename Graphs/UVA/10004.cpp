#include <bits/stdc++.h>
using namespace std;

int adj[201][201];

bool check(int v, const int n){
    int color[n];
    memset(color, -1, sizeof(color));
    color[v] = 1;

    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(adj[u][u] == 1) return false;

        for(int i = 0; i < n ; ++i){
            if(adj[u][i] == -1) continue;
            if(color[i] == -1) {
                color[i] = 1 - color[u];
                q.push(i);
            }
            else if(color[i] == color[u]) return false;
        }
    }
    return true;
}

int main(){
    int n, na;
    while(scanf("%d", &n) && n){
        scanf("%d", &na);
        memset(adj, -1, sizeof(adj));
        for(int i = 0; i < na ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a][b] = 1;
        }

        printf("%s\n", check(0,n)? "BICOLORABLE." : "NOT BICOLORABLE.");
    }


    return 0;
}