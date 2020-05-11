//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2169
//UVA 11228 - Transportation system.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<double, int> di;
vector<ii> point;
int n, r, ti;
vector<int> vst;
priority_queue<di, vector<di>, greater<di>> pq;

double dist(int p1, int p2){
    return sqrt(pow((point[p1].second-point[p2].second), 2) + pow((point[p1].first-point[p2].first), 2));
}

void process(int v){
    vst[v] = true;
    for(int i = 0; i < n ; ++i){
        if(vst[i]) continue;
        pq.push({dist(v,i), i});
    }
}

void prim(){
    vst.assign(n, false);
    process(0);
    int state = 0;
    double road = 0, rail = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        double w = x.first;
        int u = x.second;
        if(vst[u]) continue;
        if(w > r) rail+=w, state++;
        else road+=w;
        process(u);
    }

    printf("Case #%d: %d %d %d\n", ti ,++state, (int)round(road), (int)round(rail));
}

int main(){
    int t;
    scanf("%d", &t);
    for(ti = 1; ti <= t ; ++ti){
        scanf("%d%d", &n, &r);
        point.clear();
        for(int i = 0; i < n ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            point.push_back({a,b});
        }

        prim();
    }
    return 0;
}