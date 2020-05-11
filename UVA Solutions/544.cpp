//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=485&mosmsg=Submission+received+with+ID+24993607
//UVA - 544 - Heavy Cargo
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<int> parent;
vector<int> memo;
vector<pair<int,ii>> edges;
vector<vector<ii>> go;

void init(const int n){
    parent.resize(n);
    for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
    return parent[u] == u ? parent[u] : find(parent[u]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    parent[y] = x;
}

void kruskral(const int n){
    init(n);
    sort(edges.begin(), edges.end(), greater<pair<int,ii>>());
    go.assign(n, vector<ii>());
    int cnt = 0;
    for(int i = 0; i < (int)edges.size() ; ++i){
        auto x = edges[i];
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;

        if(find(u) == find(v)) continue;
        merge(u, v);
        go[u].push_back({v,w});
        go[v].push_back({u,w});
        if(++cnt == n-1) break;
    }
}

int dfs(int idx, const int destiny){
    if(idx == destiny) return 0;
    int& ans = memo[idx];
    if(ans != -1) return ans;
    ans = oo;
    for(auto x : go[idx]){
        ans = min(ans, 1+dfs(x.first, destiny));
    }
    return ans;
}

int rec(int idx, const int destiny){
    if(idx == destiny) return oo;
    int maxd = oo;
    for(auto x : go[idx]){
        if(dfs(x.first, destiny)+1 == memo[idx]){
            maxd = min(x.second, rec(x.first, destiny));
            break;
        }
    }
    return maxd;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, d, idx1, idx2, t = 0, ans;
    unordered_map<string, int> mp;
    while(cin >> n >> m && n+m){
        mp.clear();
        int cnt = 0; //index city
        string c1, c2;
        edges.clear();
        for(int i = 0; i < m ; ++i){
            cin >> c1 >> c2 >> d;
            if(mp.find(c1) == mp.end()) mp[c1] = (idx1 = cnt++);
            else idx1 = mp[c1];

            if(mp.find(c2) == mp.end()) mp[c2] = (idx2 = cnt++);
            else idx2 = mp[c2];

            edges.push_back({d,{idx1, idx2}});
        }
        
        cin >> c1 >> c2;
        int origin = mp[c1];
        int destiny = mp[c2];

        kruskral(n);
        memo.assign(n, -1);
        dfs(origin, destiny);
       
        cout << "Scenario #" << ++t << '\n';
        cout << rec(origin, destiny) << " tons\n\n";
    }

    return 0;
}