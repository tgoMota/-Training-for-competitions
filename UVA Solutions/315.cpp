//https://onlinejudge.org/external/3/315.pdf
//UVA 315 Network
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<int> parent, dfs_time, dfs_low;
vector<bool> articulation;
vector<vector<int>> adj;

void dfsArticulations(int v, int& counter, int& rootChildren, int dfsRoot){
    dfs_time[v] = dfs_low[v] = counter++;
    for(int x : adj[v]){
        if(!dfs_time[x]){
            parent[x] = v;
            if(dfsRoot == v) rootChildren++;
            dfsArticulations(x, counter, rootChildren, dfsRoot);
            if(v != dfsRoot && dfs_low[x] >= dfs_time[v]) articulation[v] = true;
            dfs_low[v] = min(dfs_low[v], dfs_low[x]);
        }else if(parent[v] != x) dfs_low[v] = min(dfs_low[v], dfs_time[x]);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        adj.assign(n+1, vector<int>());
        string line;
        cin.ignore();
        while(getline(cin, line) && line != "0"){
            string num;
            const int N = line.size();
            int cnt = 0, u;
            for(int i = 0; i < N ; ++i){
                num = "";
                while(i < N && line[i] == ' ') i++;
                while(i < N && line[i] != ' ') num += line[i++];
                int a = stoi(num);
                if(!cnt++) {
                    u = a;
                    continue;
                }
                adj[u].push_back(a);
                adj[a].push_back(u);
            }
        }
        parent.assign(n+1, 0);
        dfs_time.assign(n+1, 0);
        dfs_low.assign(n+1, 0);
        articulation.assign(n+1, false);

        for(int i = 1; i <= n ; ++i){
            if(!dfs_time[i]){
                int rootChildren = 0, counter = 1;
                dfsArticulations(i,counter, rootChildren, i);
                articulation[i] = rootChildren > 1;
            }
        }
        int cntArticulations = 0;
        for(int i = 1; i <= n ; ++i) cntArticulations += articulation[i];
        printf("%d\n", cntArticulations);
    }
    return 0;
}