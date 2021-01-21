//https://www.urionlinejudge.com.br/judge/pt/problems/view/1391
//URI 1391 - Quase Menor Caminho
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
int N, M, S, D;
vector<int> parent;
vector<vector<ii>> adj;
vector<vector<bool>> ok;
int dji(){
  vector<int> dist(N, oo);
  parent.assign(N, -1);
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0,S});
  dist[S] = 0;
  while(!pq.empty()){
    int v = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    for(ii& x : adj[v]){
      if(!ok[v][x.first]) continue;
      if(d+x.second <= dist[x.first]){
        parent[x.first] = v;
        dist[x.first] = d+x.second;
        pq.push({dist[x.first], x.first});
      }
    }
  }
  return dist[D];
}

void blockPath(int v){
  if(parent[v] == -1) return;
  ok[parent[v]][v] = false;
  blockPath(parent[v]);
}

int main(){
    while(scanf("%d%d", &N, &M) && N+M){
      scanf("%d%d", &S, &D);
      adj.assign(N+1, vector<ii>());
      ok.assign(N+1, vector<bool>(N+1, true));
      for(int i = 0; i < M ; ++i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b,c});
      }
      
      int mind = dji();
      blockPath(D);
      while(mind!=oo){
        int d = dji();
        if(d != mind){
          mind = d;
          break;
        }
        blockPath(D);
      }

      printf("%d\n", mind == oo ? -1 : mind);
    }
    return 0;
}
