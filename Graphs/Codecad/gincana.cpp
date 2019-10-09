//http://www.codcad.com/problem/119
//Gincana
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1010];
int ans, dist[1010];

void dfs(int v){
    if(dist[v] == -1) ans++;
    for(int x : adj[v]){
        if(dist[x] != -1) continue;

        dist[x] = dist[v] + 1;
        dfs(x);
    }
}

int main(){
    memset(dist, -1, sizeof(dist));
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m ; ++i){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n ; ++i)
        dfs(i);

    cout << ans << endl;

    return 0;
}