//https://www.urionlinejudge.com.br/judge/pt/problems/view/2127
//URI 2127 - Sistema Cipoviário
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int n, m;
vector<int> p;
vector<pair<int,ii>> edges;

void init(const int N){
  edges.clear();
  p.assign(N+1, 0);
  for(int i = 1; i <= N ; ++i) p[i] = i;
}

int find(int u){
  return p[u] == u ? u : find(p[u]);
}

void join(int u, int v){
  u = find(u), v = find(v);
  p[v] = u;
}

bool sameSet(int u, int v){
  return find(u) == find(v);
}

int kruskal(){
  int cost = 0;
  for(auto x : edges){
    int w = x.first;
    int u = x.second.first;
    int v = x.second.second;

    if(sameSet(u, v)) continue;
    cost+=w;
    join(u,v);
  }
  return cost;
}


int main(){
    int t = 0;
    while(scanf("%d%d", &n, &m) != EOF){
      init(n);
      for(int i = 0; i < m ; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({c, make_pair(a,b)});
      }

      sort(edges.begin(), edges.end());
      printf("Instancia %d\n", ++t);
      printf("%d\n\n", kruskal());
    }
    return 0;
}