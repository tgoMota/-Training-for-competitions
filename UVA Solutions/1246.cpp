//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246
//UVA 10305 - Ordering Tasks
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> result;
vector<int> incomingEdges;

void kahn(const int N){
    set<int> q;
    for(int i = 1; i <= N ; ++i){
        if(incomingEdges[i] == 0) q.insert(i);
    }
    while(!q.empty()){
        int u = *q.begin();
        q.erase(q.begin());
        result.push_back(u);
        for(int i = 0; i < adj[u].size() ; ++i){
            if(--incomingEdges[adj[u][i]] == 0) q.insert(adj[u][i]);
        }
    }
}

int main(){
    int n, m;
    while(cin >> n >> m && n+m){
        adj.resize(n+1);
        incomingEdges.assign(n+1, 0);
        result.clear();
        for(int i = 0; i < m ; ++i){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            incomingEdges[b]++;
        }

        kahn(n);
        for(int i = 0; i < result.size(); ++i){
            printf("%d", result[i]);
            if(i != (int)result.size()-1) printf(" ");
        }
        printf("\n");
        for(int i = 0; i < n ; ++i) adj[i].clear();
    }

    return 0;
}