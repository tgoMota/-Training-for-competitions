//https://www.urionlinejudge.com.br/judge/pt/problems/view/1391
#include <bits/stdc++.h>
using namespace std;
int n, m, s, d;
typedef pair<int,int> pii;
vector<vector<pii>> adj;
unordered_map<int,bool> isOnShortestPath;

int djikstra(int v, vector<vector<int>>& before){
    bool vst[n];
    memset(vst, false, sizeof(vst));
    vector<int> before2(n);
    before.push_back(before2);
    const int sz = before.size();
    set<pair<int,pair<int,int>>> q;
    q.insert({0,{v,0}}); //dist, {node, beforeNode}
    while(!q.empty()){
        auto aux = *q.begin();
        q.erase(q.begin());
        int dis = aux.first;
        int no = aux.second.first;
        int bef = aux.second.second;
        before[sz-1][no] = bef;
        if(no == d) return dis;
        vst[no] = true;
        for(pii x : adj[no]){
            int newv = x.first, newdist = x.second;
            if(vst[newv]) continue;
            if(isOnShortestPath.find(newv) != isOnShortestPath.end()) continue;
            q.insert({dis+newdist, {newv, no}});
        }       
    }
    return -1;
}

int onlyDjikstra(int v){
    bool vst[n];
    memset(vst, false, sizeof(vst));
    set<pair<int,int>> q;
    q.insert({0, v});
    while(!q.empty()){
        auto aux = *q.begin();
        q.erase(q.begin());
        int dis = aux.first;
        int no = aux.second;
        if(no == d) return dis;
        vst[no] = true;
        for(pii x : adj[no]){
            int newv = x.first, newdist = x.second;
            if(vst[newv]) continue;
            q.insert({dis+newdist, newv});
        }
    }
    return -1;
}

void removeEdge(int a, int b){
    for(int i = 0; i < adj[a].size() ; ++i){
        if(adj[a][i].first == b){
            adj[a].erase(adj[a].begin()+i);
            break;
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) && n+m){
        scanf("%d%d", &s, &d);
        adj.resize(n);
        for(int i = 0; i < m ; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
        }
        vector<vector<int>> before;
        int mindist = djikstra(s, before), almostMinDist = -1, prev;
        for(int i = 0; i < adj[s].size() ; ++i) {
            if(adj[s][i].first == d && adj[s][i].second == mindist) {
                adj[s].erase(adj[s].begin()+i);
                break;
            }
        }

        while(1){
            if(mindist == -1) break;
            int prev = before[before.size()-1][d];
            //isOnShortestPath[prev] = true;
            removeEdge(prev, d);
            if(djikstra(s, before) != mindist){
                before.erase(before.end()-1);
               // printf("apagou, before size = %d\n", (int)before.size());
                break;
            }
        }

        for(int i = 0; i < before.size() ; ++i){
            if(mindist == -1) break;
            int destiny = d, prev = d;
            while(prev!=s){
                prev = before[i][destiny];
                destiny = prev;
                if(prev != s) isOnShortestPath[prev] = true;
            }
        }

        printf("%d\n", djikstra(s, before));
        // const int BS = (int)before.size();
        // for(int i = 0; i < BS ; ++i) before[i].clear();
        //before.clear();
        isOnShortestPath.clear();
        for(int i = 0; i < n ; ++i) adj[i].clear();
    }
    return 0;
}