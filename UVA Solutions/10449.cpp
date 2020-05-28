//https://onlinejudge.org/external/104/10449.pdf
//UVA 10449 Traffic
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
typedef long long ll;
vector<pair<int, ii>> edges;
vector<int> busValue;
vector<int> dist;

void belmanFord(const int n){
    dist.assign(n+1, oo);
    dist[0] = 0;
    for(int i = 0; i < n-1 ; ++i){
        for(auto e : edges){
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;

            if(dist[u] != oo) dist[v] = min(dist[v], dist[u]+w);
        }
    }

    for(auto e : edges){
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if(dist[u]+w < dist[v]) dist[v] = -oo;
    }
}

int calc(int value){
    return value*value*value;
}

int main(){
    int n, t = 0;
    while(scanf("%d", &n) == 1){
        busValue.clear();
        for(int i = 0; i < n ; ++i) {
            int a;
            scanf("%d", &a);
            busValue.push_back(a);
        }

        int m;
        scanf("%d", &m);
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            edges.push_back({calc(busValue[b]-busValue[a]), {a,b}});
        }
        printf("Set #%d\n",++t);
        belmanFord(n);
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; ++i){
            int a;
            scanf("%d", &a);
            a--;
            if(dist[a] < 3 || dist[a] == oo) printf("?\n");
            else printf("%d\n", dist[a]);
        }
    }
    return 0;
}