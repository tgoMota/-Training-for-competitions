//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2001
//UVA 11060 - Beverages
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//CHECK THE LIMITS, PLEASE
int n, m;
map<string, int> idx;
vector<vector<int>> adj;
vector<string> names;
vector<int> in_degree;
int main(){
    fastio();
    int t = 0;
    while(cin >> n){
      idx.clear();
      adj.assign(n, vector<int>());
      names.resize(n);
      in_degree.assign(n, 0);
      for(int i = 0; i < n ;  ++i){
        cin >> names[i];
        idx[names[i]] = i;
      }

       cin >> m;
       for(int i = 0; i < m ; ++i){
         string a, b;
         cin >> a >> b;
         int id_a = idx[a], id_b = idx[b];
         adj[id_a].push_back(id_b);
         in_degree[id_b]++;
       }

        vector<int> order;
        set<int> q;
        for(int i = 0; i < n ; ++i){
          if(in_degree[i] == 0) q.insert(i);
        }
        while(!q.empty()){
          int v = *q.begin();
          q.erase(q.begin());
          for(int x : adj[v]){
            if(--in_degree[x] == 0) q.insert(x);
          }
          order.push_back(v);
        }
        cout << "Case #" << ++t << ": Dilbert should drink beverages in this order:";
        for(int x : order) cout << " " << names[x];
        cout << ".\n\n";
    }
    return 0;
}
