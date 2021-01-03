#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
vector<vector<int>> adj, residual;

bool bfs(int source, int sink, vector<int>& parent ,const int N){
    vector<bool> vst(N+1, false);
    queue<int> q;
    q.push(source);
    vst[source] = true;
    parent[source] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < N ; ++i){
            if(residual[v][i] <= 0 || vst[i]) continue;
            q.push(i);
            parent[i] = v;
            vst[i] = true;
        }
    }
    return vst[sink];
}

int augmentPath(int v, int minEdge, vector<int>& p){
    if(p[v] == -1) return minEdge;
    minEdge = augmentPath(p[v], min(minEdge, residual[p[v]][v]), p);
    residual[p[v]][v] -= minEdge;
    residual[v][p[v]] += minEdge;
    return minEdge;
}

int maxflow(int source, int sink, const int N){
    int mxflow = 0;
    vector<int> parent(N+1);
    while(bfs(source, sink,parent, N)){
        int pathflow = augmentPath(sink, oo, parent);
        mxflow += pathflow;
    }

    return mxflow;
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        adj.assign(n+1, vector<int>(n+1, 0));
        residual.assign(n+1, vector<int>(n+1, 0));
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            adj[a][b] = c;
            residual[a][b] = c;
        }
        int ans = maxflow(0,n-1,n);
        if(ans > 0) printf("%d\n", ans);
        else printf("Nao eh possivel produzir nenhum brinquedo\n");
    }

    return 0;
}
