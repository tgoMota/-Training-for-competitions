//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=849
//UVa 00908 - Re-connecting ...
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,pii> ppii;

const int MX = 1e4+5;
int dist[MX][MX];
bool vst[MX];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void process(int v, const int N){
    vst[v] = 1;
    for(int i = 1; i <= N ; ++i){
        if(!vst[i] && dist[v][i] != -1){
            pq.push({dist[v][i], i});
        }
    }
}

int prim(int v, const int N){
    memset(vst, false, sizeof(vst));
    process(v, N);
    int mst_cost = 0;
    while(!pq.empty()){
        auto k = pq.top();
        int u = k.second;
        int w = k.first;
        pq.pop();
        if(vst[u]) continue;
        mst_cost += w;
        process(u, N);
    }
    return mst_cost;
}

int main(){
    int n;
    int t = 0;
    while(scanf("%d", &n) != EOF){
        int old_cust = 0, new_cust = 0;
        for(int i = 0; i < n-1 ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            old_cust+=c;
        }
        memset(dist, -1, sizeof(dist));
        int k;
        scanf("%d", &k);
        for(int i = 0; i < k ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(dist[a][b] == -1 || c < dist[a][b]){
                dist[a][b] = c;
                dist[b][a] = c;
            }
        }

        int m;
        scanf("%d", &m);
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(dist[a][b] == -1 || c < dist[a][b]){
                dist[a][b] = c;
                dist[b][a] = c;
            }
        }
        new_cust = prim(1, n);

        if(t++) printf("\n");
        printf("%d\n%d\n", old_cust, new_cust);
    }
    return 0;
}