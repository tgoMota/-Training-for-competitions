//https://onlinejudge.org/external/115/11504.pdf
//UVA 11504 Dominos
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> topoSort;
vector<bool> vst;

void dfs(int v, int k){
    if(vst[v]) return;
    vst[v] = true;
    for(int x : adj[v]) {
        dfs(x, k);
    }
    if(k) topoSort.push_back(v);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        adj.assign(n+1, vector<int>());
        for(int i = 0; i < m ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
        }
        vst.assign(n+1, false);
        topoSort.clear();
        for(int i = 1; i <= n ; ++i) dfs(i, 1);
        reverse(topoSort.begin(), topoSort.end());

        vst.assign(n+1, false);
        int ans = 0;
        for(int x : topoSort){
            if(!vst[x]){
                dfs(x, 0);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}