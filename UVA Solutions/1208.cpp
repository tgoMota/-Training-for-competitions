//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3649
//UVA 1208 - Oreon
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dist;
priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
vector<bool> vst;
void process(int v, const int N){
    vst[v] = true;
    for(int i = 0; i < N ; ++i){
        if(!dist[v][i] || vst[i]) continue;
        pq.push({dist[v][i], {i,v}});
    }
}
set<pair<int,pair<int,int>>> ans;
void prim(int v, const int N){
    ans.clear();
    vst.assign(N, false);
    process(v, N);
    while(!pq.empty()){
        auto k = pq.top();
        pq.pop();
        int u = k.second.first;
        int p = k.second.second;
        int w = k.first;
        if(vst[u]) continue;
        ans.insert({w, {min(u,p), max(u,p)}});
        process(u, N);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        dist.assign(n, vector<int>(n, -1));
        cin.ignore();
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < n ; ++j){
                string str;
                cin >> str;
                str.erase(remove(str.begin(), str.end(), ','), str.end());
                dist[i][j] = stoi(str);
            }
        }

        prim(0,n);
        printf("Case %d:\n", ti);
        for(auto x : ans){
            printf("%c-%c %d\n", x.second.first + 'A', x.second.second + 'A', x.first);
        }
    }
    return 0;
}