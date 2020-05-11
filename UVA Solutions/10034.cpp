//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975
//UVA 10034 - Freckles
#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> dd;
typedef pair<double, int> di;
vector<dd> point;
priority_queue<di, vector<di>, greater<di>> pq;
vector<bool> vst;

double dist(int p1, int p2){
    return sqrt(pow((point[p1].second-point[p2].second), 2) + pow((point[p1].first-point[p2].first), 2));
}

void process(int v, const int N){
    vst[v] = true;
    for(int i = 0; i < N ; ++i){
        if(vst[i]) continue;
        pq.push({dist(v,i), i});
    }
}

double prim(int v, const int N){
    vst.assign(N, false);
    process(v, N);
    double mst_cost = 0.0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int u = x.second;
        double w = x.first;
        if(vst[u]) continue;
        mst_cost+=w;
        process(u, N);
    }
    return mst_cost;
}

int main(){
    int t, n;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d", &n);
        for(int i = 0; i < n ; ++i){
            double a, b;
            scanf("%lf%lf", &a, &b);
            point.push_back({a,b});
        }
        if(ti != 1) printf("\n");
        printf("%.2lf\n", prim(0,n));
        point.clear();
    }
    return 0;
}