#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
vector<vector<int>> adj;
vector<int> lv;

priority_queue<ll> q;

ll dfs(int v, int p){
    ll sz = 1LL;
    for(int x : adj[v]){
        if(x == p || x == v) continue;
        lv[x] = lv[v]+1;
        sz+=dfs(x, v);
    }
    ll dif = lv[v]-sz+1;
    q.push(dif);
    return sz;
}

int main(){
    int n, k;
    scanf("%d%d",&n, &k);
    adj.resize(n+1);
    lv.assign(n+1, 0);
    for(int i = 0; i < n-1 ; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);
    ll sum = 0LL;
    for(int i = 0; i < k ; ++i){
        sum += q.top();
        q.pop();
    }
    printf("%lld\n", sum);

    return 0;
}