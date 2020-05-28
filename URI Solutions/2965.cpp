//https://www.urionlinejudge.com.br/judge/pt/problems/view/2965
//URI 2965 || Delação Premiada
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int N, K;
vector<vector<int>> adj;
vector<bool> vst;
vector<int> level;
priority_queue<ii> pq;

void dfs(int idx, int lv){
    if(vst[idx]) return;
    vst[idx] = true;
    level[idx] = lv;
    pq.push({lv, idx});
    for(int x : adj[idx]){
        dfs(x, lv+1);
    }
}

int dfs2(int idx){
    if(vst[idx]) return 0;
    vst[idx] = true;
    int ans = 1;
    for(int x : adj[idx]){
        if(level[x] < level[idx]) ans += dfs2(x);
    }
    return ans;
}

int main(){
    scanf("%d%d", &N, &K);
    adj.assign(N+1, vector<int>());
    vst.assign(N+1, false);
    level.assign(N+1, 0);
    for(int i = 1; i <= N-1 ; ++i){
        int a;
        scanf("%d", &a);
        adj[i+1].push_back(a);
        adj[a].push_back(i+1);
    }

    dfs(1, 0);
    vst.assign(N+1, false);
    priority_queue<int> pq2;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        pq2.push(dfs2(x.second));
    }

    int sum = 0;
    for(int i = 0; i < K ; ++i){
        sum += pq2.top();
        pq2.pop();
    }
    printf("%d\n", sum);

    return 0;
}