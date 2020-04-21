//https://www.spoj.com/problems/PT07Z/
#include <bits/stdc++.h>
using namespace std;

vector<int>adj[10002];
int dist[10002], max_dist = INT_MIN, n, posmax; 

void dfs(int v){
    for(int x : adj[v]){
        if(dist[x] != -1) continue;
        dist[x] = dist[v] + 1;
        dfs(x);
    }
    if(dist[v] > max_dist){
        max_dist = dist[v];
        posmax = v;
    }
}

int main(){

    cin >> n;
    for(int i = 0; i < n-1 ; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    dfs(1);
    memset(dist, -1, sizeof(dist));
    dist[posmax] = 0;
    dfs(posmax);
    cout << max_dist << endl;

    return 0;
}