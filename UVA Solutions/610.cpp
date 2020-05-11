//https://onlinejudge.org/external/6/610.pdf
//UVA 610 Street Directions
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
vector<vector<int>> adj;
vector<vector<bool>> edgesVst;
vector<int> parent, dfs_low, dfs_time;

void dfs(int v, int& dfsTime, int& dfsRoot){
    dfs_low[v] = dfs_time[v] = ++dfsTime;
    for(int x : adj[v]){
        if(!dfs_time[x]){
            parent[x] = v;
            dfs(x, dfsTime, dfsRoot);
            if(dfs_low[x] > dfs_time[v]) printf("%d %d\n%d %d\n", v, x, x, v);
            else printf("%d %d\n", v, x);
            dfs_low[v] = min(dfs_low[v], dfs_low[x]);
        }else if(parent[v] != x){
            dfs_low[v] = min(dfs_low[v], dfs_time[x]);
            if(!edgesVst[v][x]) printf("%d %d\n", v, x);
            edgesVst[v][x] = edgesVst[x][v] = true;
        }
    }
}

int main(){
    int n, m;
    int t = 0;
    while(scanf("%d%d", &n, &m) && n+m){
        adj.assign(n+1, vector<int>());
        edgesVst.assign(n+1, vector<bool>(n+1, false));
        parent.assign(n+1, 0);
        dfs_low.assign(n+1, 0);
        dfs_time.assign(n+1, 0);
        for(int i = 0; i < m ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        printf("%d\n\n", ++t);

        for(int i = 1; i <= n ; ++i){
            if(!dfs_time[i]){
                int dfsTime = 0;
                dfs(i, dfsTime, i);
            }
        }
        printf("#\n");
    }
    return 0;
}