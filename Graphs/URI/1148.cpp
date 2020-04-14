#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define oo 0x3f3f3f3f
vector<ii> adj[502];
int djikstra(int t, vector<int>& dist, const int N){
    dist.assign(N+1,oo);
    dist[t] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > q;
    q.push(make_pair(0,t));
    while(!q.empty()){
        ii v = q.top();
        q.pop();
        int v2 = v.second;
        for(auto x : adj[v2]){
            if(dist[x.second] <= dist[v2] + x.first) continue;
            dist[x.second] = dist[v2] + x.first;
            q.push(make_pair(dist[x.second], x.first));
        }
    }
}

bool has(vector<ii>& a, int t){
    for(ii x : a) {
        if(x.second == t){
            x.first = 0;
            return true;
        }
    }
    return false;
}
int main(){

    int n, e;
    while(scanf("%d%d", &n, &e) && n+e){
        for(int i = 0; i < e ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(has(adj[b], a)) c = 0;
            adj[a].push_back(make_pair(c,b));
        }
        vector<int> dist;
        int qu;
        scanf("%d", &qu);
        for(int i = 0; i < qu ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            djikstra(a,dist,n);
            printf("dist = %d\n", dist[b]);
        }
        for(int i = 1; i <= n ; ++i) adj[i].clear();
    }

    return 0;
}