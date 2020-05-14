//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2870
//UVA 11770 - Lighting Away
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> topoSort;
vector<bool> vst;

void dfs(int v, bool isTopoSort){
    if(vst[v]) return;
    vst[v] = true;
    for(int x : adj[v]){
        dfs(x, isTopoSort);
    }
    if(isTopoSort) topoSort.push_back(v);
}

int main(){
    int n, m, t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d%d", &n, &m);
        adj.assign(n, vector<int>());
        for(int i = 0; i < m ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[--a].push_back(--b);
        }
        topoSort.clear();
        vst.assign(n, false);
        for(int i = 0; i < n ; ++i) dfs(i, 1); //topological Sorting

        reverse(topoSort.begin(), topoSort.end());
        vst.assign(n, false);
        int ans  = 0;
        for(int x : topoSort){
            if(!vst[x]){
                dfs(x, 0); //just traversing all nodes, because the graph might not be a DAG
                ans++;
            }
        }
        printf("Case %d: %d\n",ti, ans);
    }
    return 0;
}