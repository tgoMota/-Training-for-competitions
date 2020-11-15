#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<pair<int,ii>> edges;

vector<int> parent;
void init(const int N){
  parent.resize(N+1);
  for(int i = 1; i <= N ; ++i) parent[i] = i;
}

int find(int u){
  return parent[u] == u ? u : find(parent[u]);
}

void merge(int x, int y){
  x = find(x), y = find(y);
  parent[y] = x;
}

int kruskalMin(const int N){
  init(N);
  sort(edges.begin(), edges.end());
  int mst_cost = 0;
  for(auto x : edges){
    int w = x.first;
    int u = x.second.first;
    int v = x.second.second;

    if(find(u) == find(v)) continue;

    mst_cost+=w;
    merge(u,v);
  }

  return mst_cost;
}

bool cmp(auto a, auto b){
  return a.first > b.first;
}

int kruskalMax(const int N){
  init(N);
  sort(edges.begin(), edges.end(), cmp);
  int mst_cost = 0;
  for(auto x : edges){
    int w = x.first;
    int u = x.second.first;
    int v = x.second.second;

    if(find(u) == find(v)) continue;

    mst_cost+=w;
    merge(u,v);
  }

  return mst_cost;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < m ; ++i){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edges.push_back({c, {a,b}});
  }

  


  return 0;
}