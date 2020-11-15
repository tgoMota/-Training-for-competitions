//https://www.urionlinejudge.com.br/judge/pt/problems/view/1905
//URI 1905 - Polícia e Ladrão
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
const int N = 5, M = 5;

int main(){
  int t, m[N][M];
  scanf("%d", &t);
  while(t--){
    for(int i = 0; i < N ; ++i)
      for(int j = 0; j < M ; ++j) scanf("%d", &m[i][j]);
    
    bool vst[5][5];
    memset(vst, false, sizeof(vst));
    queue<ii> q;
    q.push({0,0});
    bool ok = false;
    while(!q.empty()){
      auto x = q.front();
      q.pop();
      int u = x.first, v = x.second;
      if(vst[u][v] || m[u][v]) continue;
      vst[u][v] = true;
      if(u == N-1 && v == M-1){
        ok = true;
        break;
      }
      for(int i = 0; i < 4 ; ++i){
        int dirx = dx[i]+u;
        int diry = dy[i]+v;
        if(dirx < 0 || dirx >= N || diry < 0 || diry >= M) continue;
        if(vst[dirx][diry] || m[dirx][diry]) continue;
        q.push({dirx, diry});
      }
    }

    printf("%s\n", ok ? "COPS" : "ROBBERS");
  }
  return 0;
}