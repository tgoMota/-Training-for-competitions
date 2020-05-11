//https://onlinejudge.org/external/12/1235.pdf
//UVA - 1235 Anti Brute Force Lock
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<vector<ii>> adj;
vector<string> ver;
vector<int> vst;
priority_queue<ii, vector<ii>, greater<ii>> pq;

int calc_rolls(int u, int v){
    int rolls = 0;
    for(int i = 0; i < 4 ; ++i){
        int digitu = ver[u][i] - '0', digitv = ver[v][i] - '0';
        int mindigit = min(digitu, digitv), maxdigit = max(digitu, digitv);
        rolls += min(maxdigit-mindigit, 10-maxdigit+mindigit);
    }
    return rolls;
}

void process(int v){
    vst[v] = true;
    for(auto x : adj[v]){
        if(vst[x.first] || x.first == v) continue;
        pq.push({x.second, x.first});
    }
}

int prim(int v, const int N){
    vst.assign(N, false);
    process(v);
    int mst_cost = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int u = x.second;
        int w = x.first;
        if(vst[u]) continue;
        mst_cost+=w;
        process(u);
    }

    return mst_cost;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int m, n;
        scanf("%d", &m);
        n = m+1;
        ver.resize(n);
        ver[0] = "0000";

        int plus = INT_MAX;
        for(int i = 1; i < n ; ++i) {
            cin >> ver[i];
            plus = min(plus, calc_rolls(i, 0));
        }
        
        adj.assign(n, vector<ii>());
        for(int i = 1; i < n ; ++i){
            for(int j = i+1; j < n ; ++j){
                if(i == j) continue;
                int w = calc_rolls(i, j);
                adj[i].push_back({j,w});
                adj[j].push_back({i,w});
            }
        }
        printf("%d\n", prim(1, n)+plus);
    }
    return 0;
}