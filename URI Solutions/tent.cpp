#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
vector<set<int>> adj;
vector<unordered_map<int,bool>> new_adj;
vector<vector<int>> scc;
vector<int> id_component;
int n, m;
vector<bool> vst;
vector<int> dfs_num, dfs_low, st;
int lastVisited;
void init(const int n){
    dfs_num.assign(n, 0);
    dfs_low.assign(n, 0);
    vst.assign(n, false);
    st.clear();
}
void tarjanSCC(int v, int& dfsCounter){
    dfs_num[v] = dfs_low[v] = ++dfsCounter;
    vst[v] = true;
    st.push_back(v);
    for(int u : adj[v]){
        if(!dfs_num[u]) tarjanSCC(u, dfsCounter);
        if(vst[u]) dfs_low[v] = min(dfs_low[v], dfs_low[u]);
    }

    if(dfs_low[v] == dfs_num[v]){
        vector<int> new_scc;
        int idx = (int)scc.size();
        while(1){
            int t = st.back();
            st.pop_back();
            id_component[t] = idx;
            vst[t] = false;
            new_scc.push_back(t);
            if(t == v) break;
        }
        scc.push_back(new_scc);
    }
}

// void print(){
//   for(int i = 0; i < (int)scc.size() ; ++i){
//     cout << i << ": ";
//     for(auto u : new_adj[i]){
//       int x = u.first;
//       cout << x << " ";
//     }
//     cout << '\n';
//   }
// }

// void printSCC(){
//     trace("SCC");
//     int idx = 0;
//     for(vector<int>& scc : scc){
//         cout << idx++ << ": ";
//         for(int i = 0; i < (int)scc.size() ; ++i){
//             if(i) printf(" ");
//             printf("%d", scc[i]);
//         }
//         printf("\n");
//     }
// }

int main(){
    fastio();
    cin >> n >> m;
    adj.assign(n+1, set<int>());
    id_component.assign(n+1, -1);
    new_adj.assign(n+1, unordered_map<int,bool>());
    for(int i = 0; i < m ; ++i){
      int a, b;
      cin >> a >> b;
      adj[a].insert(b);
    }
    init(n+1);
    for(int i = 1, dfsCounter = 0; i <= n ; ++i) {
        if(!dfs_num[i]) tarjanSCC(i, dfsCounter);
    }
    const int N = (int)scc.size();
    vector<int> in_deg(N+1, 0), deg(N+1, 0);
    for(int i = 1; i <= n ; ++i){
      for(int x : adj[i]){
        if(id_component[i] != id_component[x]){
          if(new_adj[id_component[i]][id_component[x]]) continue;
          new_adj[id_component[i]][id_component[x]] = true;
          in_deg[id_component[x]]++;
          deg[id_component[x]]++;
          deg[id_component[i]]++;
        }
      }
    }
    queue<int> q;
    int root = 0;
    for(int i = 0; i < N ; ++i){
      if(in_deg[i] == 0){
        q.push(i);
      }
    }
    vector<int> topo;
    int cnt = 0;
    bool ok = true;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      topo.push_back(v);
      ++cnt;
      if(cnt == 1 || cnt == N) ok &= (deg[v] == 1);
      else ok &= (deg[v] == 2);
      if(!ok || cnt == N) break;
      for(auto u : new_adj[v]){
        int x = u.first;
        if(--in_deg[x] == 0) q.push(x);
      }
    }

    if(ok && cnt == N) cout << "Bolada\n";
    else cout << "Nao Bolada\n";
    return 0;
}

