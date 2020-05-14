//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2938
//UVA 11838 - Come and Go
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dfs_num, dfs_low, st, vst;

void dfs(int v, int& dfsTime, int& SCC){
    dfs_num[v] = dfs_low[v] = ++dfsTime;
    st.push_back(v);
    vst[v] = 1;
    for(int x : adj[v]){
        if(!dfs_num[x]) dfs(x, dfsTime, SCC);
        if(vst[x]) dfs_low[v] = min(dfs_low[v], dfs_low[x]);
    }

    if(dfs_low[v] == dfs_num[v]){
        SCC++;
        while(1){
            int x = st.back();
            st.pop_back();
            vst[x] = 0;
            if(x == v) break;
        }
    }
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m){
        adj.assign(n+1, vector<int>());
        dfs_num.assign(n+1, 0);
        dfs_low.assign(n+1, 0);
        st.clear();
        vst.assign(n+1, 0);

        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            adj[a].push_back(b);
            if(c == 2) adj[b].push_back(a);
        }
        int SCC = 0, dfsTime = 0;
        for(int i = 1; i <= n ; ++i){
            if(!dfs_num[i]) dfs(i, dfsTime = 0, SCC);
        }

        printf("%d\n", SCC == 1);
    }
    return 0;
}