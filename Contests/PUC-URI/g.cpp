#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<vector<int>> adj;
vector<bool> vst;

int dfs(int v, int r){
    if(r == 0) return 0;
    int ans = 0;
    for(int x : adj[v]){
        if(vst[x]) continue;
        vst[x] = true;
        ans += 1+dfs(x, r-1);
    }
    return ans;
}

bool has(vector<int>& a, int b){
    for(int x : a) if(x == b) return true;
    return false;
}

int main(){
    cin >> N >> K;
    adj.resize(N+1);
    for(int i = 1; i < N ; ++i){
        int a, b;
        cin >> a >> b;
        if(has(adj[a], b)) continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vst.assign(N+1, false);
    int ans = 0;
    for(int i = 1; i <= N ; ++i){
        vst[i] = true;
        printf("%d\n",1+dfs(i, K));
        for(int j = 1; j <= N ; ++j) vst[j] = false;
    }

    return 0;
}