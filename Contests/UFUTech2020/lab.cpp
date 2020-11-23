#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
typedef pair<int,int> ii;
const int NAX = 505;
int grid[NAX][NAX], dist[NAX][NAX];
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

pair<int,ii> bfsMax(int posi, int posj, const int n, const int m){
    pair<int,ii> maxv = {-oo, {-1,-1}};
    memset(dist, -1, sizeof(dist));
    queue<ii> q;
    q.push({posi, posj});
    dist[posi][posj] = 0;
    while(!q.empty()){
      auto x = q.front();
      q.pop();
      int xi = x.first;
      int xj = x.second;
      for(int i = 0; i < 4 ; ++i){
        int newx = xi+dx[i];
        int newy = xj+dy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= m || dist[newx][newy] != -1) continue;
        if(!grid[newx][newy]) continue;
        dist[newx][newy] = dist[xi][xj]+1;
        if(dist[newx][newy] > maxv.first) maxv = {dist[newx][newy],make_pair(newx,newy)};
        q.push({newx, newy});
      }
    }
    return maxv;
}

int main(){
  int n, m;
  fastio();
  while(cin >> n >> m && n+m){
    int posi = -1, posj = -1;
    for(int i = 0; i < n ; ++i){
      string s;
      cin >> s;
      for(int j = 0; j < m ; ++j) {
        grid[i][j] = (s[j] == '.');
        if(grid[i][j] && posi == -1){
          posi = i;
          posj = j;
        }
      }
    }

    pair<int,ii> p1 = bfsMax(posi, posj, n, m);
    pair<int,ii> p2 = bfsMax(p1.second.first, p1.second.second, n, m);
    printf("%d\n", p2.first);
  }

  return 0;
}