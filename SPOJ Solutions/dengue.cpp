//https://br.spoj.com/problems/DENGUE/
#include <bits/stdc++.h>
using namespace std;
int n, ans, max_dist = INT_MIN, dist[110], min_dist = INT_MAX, teste;
vector<int> adj[110];

void dfs(int v){
    for(int x: adj[v]){
        if(dist[x] != -1) continue;
        dist[x] = dist[v] + 1;
        dfs(x);
    }

    if(dist[v] > max_dist) max_dist = dist[v];
}

int main(){
    while(cin >> n && n!=0){
        int a, b;
        for(int i = 1; i <= n-1 ; ++i){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        min_dist = INT_MAX;
        for(int i = 1; i <= n ; ++i){
            memset(dist, -1, sizeof(dist));
            max_dist = INT_MIN;
            dist[i] = 0;
            dfs(i);
            if(max_dist < min_dist){ 
                min_dist = max_dist;
                ans = i;
            }
        }
        cout << "Teste " << ++teste << endl;
        cout << ans << endl;
        for(int i = 1; i <= n ; ++i) adj[i].clear();
    }

    return 0;
}