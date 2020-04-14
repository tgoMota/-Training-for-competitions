#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> adj;
int dfs(int node){
    if(adj[node].size() == 0) return 0;
    int& ans = dp[node];
    if(ans != -1) return ans;
    for(int x : adj[node]) ans= max(ans, dfs(x)+1);
    return ans;
}

int main(){

    int n, m;
    cin >> n >> m;
    adj.resize(n+1);
    for(int i = 1; i <= m ; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dp.assign(n+1, -1);
    int ans = 0;
    for(int i = 1; i <= n ; ++i) ans = max(ans, dfs(i));
    printf("%d\n", ans);

    return 0;
}