//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=183
//UVA 247 Calling Circles
#include <bits/stdc++.h>
using namespace std;
map<string,int> idx;
vector<int> st, dfs_num, dfs_low, vst;
vector<string> person;
vector<vector<int>> adj;

void dfs(int v, int& dfsTime, int& numberSCC){
    dfs_num[v] = dfs_low[v] = ++dfsTime;
    vst[v] = 1;
    st.push_back(v);
    for(int x : adj[v]){
        if(!dfs_num[x]) dfs(x, dfsTime, numberSCC);
        if(vst[x]) dfs_low[v] = min(dfs_low[v], dfs_low[x]);
    }

    if(dfs_num[v] == dfs_low[v]){
        int cnt = 0;
        while(1){
            int x = st.back();
            st.pop_back();
            vst[x] = 0;
            if(cnt++) printf(", %s", person[x].c_str());
            else printf("%s", person[x].c_str());
            if(x == v) break;
        }
        printf("\n");
    }
}

bool exist(vector<int>& a, int u){
    for(int x : a) if(x == u) return true;
    return false;
}

int main(){
    int n, m, t = 0;
    while(scanf("%d%d", &n, &m) && n+m){
        if(t) printf("\n");
        idx.clear();
        person.resize(n);
        adj.assign(n, vector<int>());
        string a, b;
        int id = 0, u, v;
        for(int i = 0; i < m ; ++i){
            cin >> a >> b;
            if(idx.find(a) == idx.end()) idx[a] = id, person[id] = a, u = id++;
            else u = idx[a];

            if(idx.find(b) == idx.end()) idx[b] = id, person[id] = b, v = id++;
            else v = idx[b];

            if(!exist(adj[u], v)) adj[u].push_back(v);
           // adj[v].push_back(u);
        }
        dfs_num.assign(n, 0);
        dfs_low.assign(n, 0);
        vst.assign(n, 0);
        int dfsTime = 0, numberSCC = 0;
        printf("Calling circles for data set %d:\n", ++t);
        for(int i = 0; i < n ; ++i){
            if(!dfs_num[i]) dfs(i, dfsTime, numberSCC);
        }
    }
    return 0;
}