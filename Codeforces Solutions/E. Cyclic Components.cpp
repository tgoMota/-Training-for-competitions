//http://codeforces.com/contest/977/problem/E
#include <bits/stdc++.h>
using namespace std;

int dist[1000002], ans, n, m;
vector<int> adj[1000002];

void dfs(int v){
    for(int x : adj[v]){
        if(dist[x] > 0 || adj[v].size() != 2) continue;
        if(dist[x] == 0 && dist[v] == 1) continue;
        if(dist[x] == 0) ans++;
        dist[x] = dist[v] + 1;
        dfs(x);
    }
}

int main(){
    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n ; ++i){
        if(adj[i].size() != 2) continue;
        if(dist[i] == -1) dist[i] = 0;
        dfs(i);
    }   

    cout << ans << endl;
    return 0;
}