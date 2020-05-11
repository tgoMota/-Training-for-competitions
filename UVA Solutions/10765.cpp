//https://onlinejudge.org/external/107/10765.pdf
//UVA 10765 Doves and Bombs
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<vector<int>> adj;
vector<int> parent, dfs_num, dfs_low;
vector<int> ans;

void dfs(int v, int& dfsTime){
    dfs_num[v] = dfs_low[v] = ++dfsTime;
    for(int x : adj[v]){
        if(!dfs_num[x]){
            parent[x] = v;
            dfs(x, dfsTime);
            if(dfs_low[x] >= dfs_num[v]) ans[v]++;
            dfs_low[v] = min(dfs_low[v], dfs_low[x]);
        }else if(parent[v] != x){
            dfs_low[v] = min(dfs_low[v], dfs_num[x]);
        }
    }
}

int main(){
    int n, k;
    while(scanf("%d%d", &n, &k) && n+k){
        int a, b;
        adj.assign(n, vector<int>());
        while(scanf("%d%d", &a, &b) && (a!=-1 || b!=-1)){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        parent.assign(n, 0);
        dfs_num.assign(n, 0);
        dfs_low.assign(n, 0);
        ans.assign(n, 0);
        for(int i = 0; i < n ; ++i){
            if(!dfs_num[i]){
                int dfsTime = 0;
                dfs(i, dfsTime);
                ans[0]--;
            }
        }
        vector<ii> ans2;
        for(int i = 0; i < n ; ++i) ans2.push_back({ans[i], i});
        sort(ans2.begin(), ans2.end(), [&](ii& a, ii&b){
            if(a.first != b.first) return a.first>b.first;
            return a.second < b.second;
        });

        for(int i = 0; i < k ; ++i) printf("%d %d\n", ans2[i].second, ans2[i].first+1);
        printf("\n");
    }
    return 0;
}