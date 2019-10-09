//http://codeforces.com/problemset/problem/104/C
#include <bits/stdc++.h>
using namespace std;
#define MAX 102
int dist[MAX];
string ans;
vector<int> adj[MAX];

void dfs(int v){
    for(int x: adj[v]){
        if(dist[x] != -1) continue;
        dist[x] = dist[v] + 1;
        dfs(x);
    }
}

void testAns(int n){
    for(int i = 1; i <= n ; ++i){
        if(dist[i] == -1){
            ans = "NO";
            return;
        }
    }
     ans = "FHTAGN!";
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m ; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    dfs(1);

    if(n != m)
        ans = "NO";
    else{
        testAns(n);
    }

    cout << ans << endl;
    return 0;
}