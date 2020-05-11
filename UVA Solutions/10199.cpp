//https://onlinejudge.org/external/101/10199.pdf
//UVA 10199 Tourist Guide
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> parent, dfs_num, dfs_low, articulations;
vector<vector<int>> adj;

void dfs(int v, int& dfsTime, int& rootChildren, int root){
    dfs_num[v] = dfs_low[v] = ++dfsTime;
    for(int x : adj[v]){
        if(!dfs_num[x]){
            parent[x] = v;
            if(v == root) rootChildren++;
            dfs(x, dfsTime, rootChildren, root);

            if(dfs_low[x] >= dfs_num[v]) articulations[v] = 1;
            dfs_low[v] = min(dfs_low[v], dfs_low[x]);
        }
        else if(parent[v] != x){
            dfs_low[v] = min(dfs_low[v], dfs_num[x]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t = 0;
    while(cin >> n && n){
        if(t) cout << endl;
        map<string, int> index;
        vector<string> city(n);
        for(int i = 0; i < n ; ++i){
            string s;
            cin >> s;
            index[s] = i;
            city[i] = s;
        }

        int m;
        cin >> m;
        adj.assign(n, vector<int>());
        for(int i = 0; i < m ; ++i){
            string a, b;
            cin >> a >> b;
            int u = index[a];
            int v = index[b];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        parent.assign(n, 0);
        dfs_num.assign(n, 0);
        dfs_low.assign(n, 0);
        articulations.assign(n, 0);

        for(int i = 0; i < n ; ++i){
            if(!dfs_num[i]){
                int dfsTime = 0, rootChildren = 0;
                dfs(i, dfsTime, rootChildren, i);
                articulations[i] = rootChildren > 1;
            }
        }

        cout << "City map #" << ++t << ": " 
        << count(articulations.begin(), articulations.end(), 1) 
        << " camera(s) found\n";
        set<string> ans;
        for(int i = 0; i < articulations.size() ; ++i){
            if(articulations[i]) ans.insert(city[i]);
        }

        for(string s : ans) cout << s << '\n';
    }
    return 0;
}