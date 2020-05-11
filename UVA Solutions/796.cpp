//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737
//UVA 796 - Critical Links
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> parent, dfs_num, dfs_low;
vector<vector<int>> adj;
vector<ii> bridges;

void dfs(int v, int& dfsTime){
    dfs_num[v] = dfs_low[v] = ++dfsTime;
    for(int x : adj[v]){
        if(!dfs_num[x]){
            parent[x] = v;
            dfs(x, dfsTime);;
            if(dfs_low[x] > dfs_num[v]) bridges.push_back({min(x,v), max(x,v)});
            dfs_low[v] = min(dfs_low[v], dfs_low[x]);
        }
        else if(parent[v] != x) dfs_low[v] = min(dfs_low[v], dfs_num[x]);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        adj.assign(n, vector<int>());
        for(int i = 0; i < n ; ++i){
            int u;
            scanf("%d", &u);
            string s, num = "";
            cin >> s;
            for(int j = 0; j < s.size() ; ++j) if(isdigit(s[j])) num+=s[j];
            int m = stoi(num);
            for(int j = 0; j < m ; ++j) {
                int a;
                scanf("%d", &a);
                adj[u].push_back(a);
                adj[a].push_back(u);
            }
        }

        parent.assign(n, 0);
        dfs_num.assign(n, 0);
        dfs_low.assign(n, 0);
        bridges.clear();
        for(int i = 0; i < n ; ++i){
            if(!dfs_num[i]){
                int dfsTime = 0;
                dfs(i, dfsTime);
            }
        }

        printf("%d critical links\n", (int)bridges.size());
        sort(bridges.begin(), bridges.end());
        for(auto x : bridges) printf("%d - %d\n", x.first, x.second);
        printf("\n");
    }
    return 0;
}