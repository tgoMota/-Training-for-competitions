#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int>> adj;
vector<int> pieces;
int dif;

int dfs(int node){
    if(adj[node].size() == 0) return 0;
    int tot = 0;
    for(int x : adj[node]) tot += 1+dfs(x);
    
    for(int i = 1; i < adj[node].size() ; ++i){
        if(pieces[adj[node][i]] != pieces[adj[node][i-1]]){
            dif = 1;
            break;
        }
    }
    return pieces[node] = tot;
}

int main(){
    cin >> N;
    adj.resize(N+1);
    pieces.assign(N+1, 0);
    for(int i = 1; i <= N; ++i){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    dfs(0);
    if(dif) printf("mal\n");
    else printf("bem\n");

    return 0;
}