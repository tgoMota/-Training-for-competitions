//https://www.urionlinejudge.com.br/judge/pt/problems/view/1552
//URI 1552 - Resgate em Queda Livre
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
vector<ii> p;
vector<vector<int>> adj;
vector<pair<int,ii>> edges;
vector<int> parent;

void init(int n){
  parent.resize(n);
  for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
  return parent[u] == u ? u : find(parent[u]);
}

void merge(int u, int v){
  u = find(u), v = find(v);
  parent[u] = v;
}

double kruskral(int n){
  init(n);
  sort(edges.begin(), edges.end());
  double mst = 0;
  for(auto e : edges){
    int w = e.first;
    int u = e.second.first;
    int v = e.second.second;
    if(find(u) == find(v)) continue;
    mst+=sqrt(w);
    merge(u,v);
  }
  return mst;
}

int dist(ii& a, ii& b){
  return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        edges.clear();
        p.clear();
        int n;
        scanf("%d", &n);
        adj.assign(n, vector<int>(n));
        for(int i = 0; i < n ; ++i){
          int a, b;
          scanf("%d%d", &a, &b);
          p.push_back({a,b});
        }

        for(int i = 0; i < n ; ++i){
          for(int j = i+1; j < n ; ++j){
            adj[i][j] = adj[j][i] = dist(p[i], p[j]);
            edges.push_back({adj[i][j], {i,j}});
          }
        }
      double ans = kruskral(n)/100;
      printf("%.2lf\n", ans);
    }
    return 0;
}
