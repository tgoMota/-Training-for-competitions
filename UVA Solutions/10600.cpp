//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541
//10600 - ACM Contest and Blackout
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<int> parent;
vector<pair<int, ii>> edges;
vector<bool> belongToMst;

void init(const int n){
    parent.resize(n);
    for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
    return parent[u] == u ? u : find(parent[u]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    parent[y] = x;
}

int kruskal(const int n){
    init(n);
    sort(edges.begin(), edges.end());
    belongToMst.assign((int)edges.size(), false);
    int cost = 0, cnt = 0;
    for(int i = 0; i < (int)edges.size() ; ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)) continue;
        belongToMst[i] = true;
        merge(u,v);
        cost+=w;
    }
    return cost;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d%d", &n, &m);
        edges.clear();
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.push_back({c,{--a,--b}});
        }

        int firstCost = kruskal(n);
        int secondCost = oo;
        for(int k = 0; k < m ; ++k){
            if(!belongToMst[k]) continue;
            init(n);
            int cnt = 0, cost = 0;
            for(int i = 0; i < m ; ++i){
                if(i == k) continue;
                auto x = edges[i];
                int u = x.second.first;
                int v = x.second.second;
                int w = x.first;
                if(find(u) == find(v)) continue;
                merge(u,v);
                cost+=w;
                if(++cnt == n-1){
                    secondCost = min(secondCost, cost);
                    break;
                }
            }
        }
        printf("%d %d\n",firstCost, secondCost == oo ? firstCost : secondCost);
    }
    return 0;
}