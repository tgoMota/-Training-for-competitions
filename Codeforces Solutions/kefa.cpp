//http://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100002];
int max_dist = INT_MIN, dist[100002], cats[100002], n, m, ans;

void dfs(int v){
    for(int x : adj[v]){
        if(dist[x] != -1) continue;
        if(cats[x]) dist[x] = dist[v] + 1;
        else if(dist[v] > m) dist[x] = dist[v];
        else dist[x] = 0;
        dfs(x);
    }

    if(v != 1 && adj[v].size() == 1 && dist[v] <= m) ans++;
}

int main(){

    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> cats[i];
    }

    for(int i = 1; i <= n-1 ; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dist, -1, sizeof(dist));
    if(cats[1]) dist[1] = 1;
    else dist[1] = 0;
    dfs(1);
    

    cout << ans << endl;
    return 0;
}