//https://www.urionlinejudge.com.br/judge/pt/problems/view/1152
//URI 1152 - Estradas Escuras
#include <bits/stdc++.h>
using namespace std;
vector<int> parent, rnk;
typedef pair<int,int> ii;
multiset<pair<int,ii>> edges;
int find(int u){
  return parent[u] == u ? u : find(parent[u]);
}

void merge(int u, int v){
  u = find(u), v = find(v);
  parent[v] = u;
}

void init(int n){
  parent.resize(n);
  rnk.assign(n, 0);
  for(int i = 0; i < n ; ++i) parent[i] = i;
}

int main(){
  int n, m;
  while(scanf("%d%d", &n, &m) && n+m){
    init(n);
    int a, b, c;
    edges.clear();
    for(int i = 0; i < m ; ++i){
      scanf("%d%d%d", &a, &b, &c);
      edges.insert({c,{a,b}});
    }

    int ans = 0;
    for(auto x : edges){
      int w = x.first;
      int u = x.second.first;
      int v = x.second.second;
      if(find(u) == find(v)){
        ans+=w;
        continue;
      }
      merge(u,v);
    }

    printf("%d\n", ans);

  }

  return 0;
}