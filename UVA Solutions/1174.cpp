//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3615
//1174 - IP-TV
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
map<string,vector<pair<string,int>>> adj;
set<string> vst;
priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;

void process(string s){
    vst.insert(s);
    for(auto x : adj[s]){
        if(vst.find(x.first) != vst.end()) continue;
        pq.push({x.second, x.first});
    }
}

int prim(string v, const int n){
    vst.clear();
    process(v);
    int mst_cost = 0;
    while(!pq.empty()){
        auto x = pq.top();
        string u = x.second;
        int w = x.first;
        pq.pop();
        if(vst.find(u) != vst.end()) continue;
        process(u);
        mst_cost += w;
    }
    return mst_cost;
}

int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        adj.clear();
        if(ti > 1) cout << endl;
        int n, m;
        cin >> n >> m;

        string a, b;
        int c;
        for(int i = 1; i <= m ; ++i){
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        int mst_cost = prim(a,n);
        cout << mst_cost << endl;

    }
    return 0;
}