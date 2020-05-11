//https://onlinejudge.org/external/104/10462.pdf
//UVA 10462 - Is There A Second Way Left ?
#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;
typedef pair<int,int> ii;
vector<int> parent;
vector<pair<int,ii>> edges;
vector<int> belongToMst;
void init(const int n){
    parent.resize(n);
    for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
    return parent[u] == u ? u : find(parent[u]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int kruskal(const int n){
    init(n);
    sort(edges.begin(), edges.end());
    belongToMst.assign((int)edges.size(), false);
    int cost = 0, cnt = 0;
    for(int i = 0; i < edges.size() ; ++i){
        auto x = edges[i];
        int u = x.second.first;
        int v = x.second.second;
        int w = x.first;
        if(find(u) == find(v)) continue;
        cost+=w;
        merge(u,v);
        belongToMst[i] = true;
        if(++cnt == n-1) break;
    }
    return cnt == n-1;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        scanf("%d%d", &n, &m);
        edges.clear();
        for(int i = 0; i < m ;++i){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            --a, --b;
            edges.push_back({c, {a, b}});
        }
        printf("Case #%d : ", ti);
        bool thereIsAWay = kruskal(n);
        if(!thereIsAWay) {
            printf("No way\n");
            continue;
        }
        bool thereIsASecondWay = false;
        int minCostSecondWay = oo;
        for(int k = 0; k < m ; ++k){
            if(!belongToMst[k]) continue;
            init(n);
            int cnt = 0;
            int costSecondWay = 0;
            for(int i = 0; i < edges.size(); ++i){
                if(i == k) continue;
                auto x = edges[i];
                int w = x.first;
                int u = x.second.first;
                int v = x.second.second;

                if(find(u) == find(v)) continue;
                merge(u,v);
                costSecondWay+=w;
                if(++cnt == n-1) {
                    thereIsASecondWay = true;
                    minCostSecondWay = min(minCostSecondWay, costSecondWay);
                    break;
                }
            }
        }
        if(thereIsASecondWay) printf("%d\n", minCostSecondWay);
        else printf("No second way\n");
    }
    return 0;
}