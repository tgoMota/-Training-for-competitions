//https://onlinejudge.org/external/117/11709.pdf
//UVA 11709 Trust groups
#include <bits/stdc++.h>
using namespace std;
map<string, int> idx;
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
            vst[x] = 0;
            st.pop_back();
            if(x == v) break;
        }
    }
}

int main(){
    int p, t;
    while(scanf("%d%d", &p, &t) && p+t){
        string a, b;
        int cnt = 0;
        idx.clear();
        for(int i = 0; i < p ; ++i){
            cin >> a >> b;
            idx[b+a] = i;
        }

        adj.assign(p, vector<int>());
        for(int i = 0; i < t ; ++i){
            cin >> a >> b;
            int u = idx[b+a];
            cin >> a >> b;
            int v = idx[b+a];
            adj[u].push_back(v);
        }

        dfs_num.assign(p, 0);
        dfs_low.assign(p, 0);
        vst.assign(p,0);
        st.clear();
        int SCC = 0, dfsTime = 0;
        for(int i = 0; i < p ; ++i){
            if(!dfs_num[i]) dfs(i, dfsTime = 0, SCC);
        }

        printf("%d\n", SCC);

    }

    return 0;
}