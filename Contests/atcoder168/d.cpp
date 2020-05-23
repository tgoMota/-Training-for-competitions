#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> adj[n];
    for(int i = 0; i < m ; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);    
    }

    vector<int> parent(n, -1);
    queue<pair<int,int>> q;
    q.push({0,0});
    int cnt = 0;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(parent[x.first] != -1) continue;
        cnt++;
        parent[x.first] = x.second;
        for(int v : adj[x.first]){
            if(parent[v] != -1) continue;
            q.push({v, x.first});
        }
    }
    if(cnt != n) printf("No\n");
    else{
        printf("Yes\n");
        for(int i = 1; i < n ; ++i){
            printf("%d\n", parent[i]+1);
        }
    }
    return 0;
}