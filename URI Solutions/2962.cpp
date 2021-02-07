//https://www.urionlinejudge.com.br/judge/pt/problems/view/2962
//URI 2962 - Arte Valiosa
#include <bits/stdc++.h>
using namespace std;
//CHECK THE LIMITS, PLEASE
int M, N, K;

struct circle{
  int x, y, r;
  bool north, south, east, west;
  circle(){
    north = south = east = west = false;
  }
  circle(int _x, int _y, int _r){
    x = _x;
    y = _y;
    r = _r;
    north = y-r <= 0;
    south = y+r >= M;
    west = x-r <= 0; 
    east = x+r >= N; 
  }

  void unite(circle c){
    north |= c.north;
    south |= c.south;
    east |= c.east;
    west |= c.west;
  }

  bool block_sides(){
    return (south && east) || (west && north) || (south && north) || (west && east);
  }
};

int dist(circle &a , circle &b){
  return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool collision(circle &a, circle &b){
  return dist(a,b) <= (a.r+b.r)*(a.r+b.r);
}

vector<circle> v;
vector<vector<int>> adj;
vector<bool> vst;

circle dfs(int x){
  circle c = v[x];
  vst[x] = true;
  for(int u : adj[x]){
    if(vst[u]) continue;
    c.unite(dfs(u));
  }
  return c;
}
int main(){
    scanf("%d%d%d", &N, &M, &K);
    v.resize(K);
    for(circle& c : v){
      int x,y,r;
      scanf("%d%d%d", &x, &y, &r);
      c = circle(x,y,r);
    }
    adj.assign(K, vector<int>());
    for(int i = 0; i < K ; ++i){
      for(int j = i+1; j < K ; ++j){
        if(collision(v[i], v[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    vst.assign(K, false);
    bool can_rob = true;
    for(int i = 0; i < K ; ++i){
      if(vst[i]) continue;
      circle intersection = dfs(i);
      if(intersection.block_sides()) can_rob = false;
    }

    if(can_rob) printf("S\n");
    else printf("N\n");

    return 0;
}
