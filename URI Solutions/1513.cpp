//https://www.urionlinejudge.com.br/judge/pt/problems/view/1513
//URI 1513 - Cavalo
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int n, m, k, dx[]={2,2,-2,-2,1,1,-1,-1}, dy[] = {1,-1,1,-1,2,-2,2,-2};
int posi, posj, base;
int idxp = 0;
vector<vector<int>> new_dist, dist;
map<ii, int> counterP;
vector<string> grid;

void bfs(int si, int sj){
  dist.assign(n, vector<int>(m, -1));
  queue<ii> q;
  q.push({si, sj});
  dist[si][sj] = 0;
  while(!q.empty()){
    ii x = q.front();
    q.pop();
    for(int i = 0; i < 8 ; ++i){
      int new_x = x.first + dx[i];
      int new_y = x.second + dy[i];
      if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || grid[new_x][new_y] == '#') continue;
      if(dist[new_x][new_y] != -1) continue;
      dist[new_x][new_y] = dist[x.first][x.second] + 1;
      q.push({new_x, new_y});
    }
  }
  int id_s = counterP[{si,sj}];
  for(auto it : counterP){
    int id_p = it.second;
    int x = it.first.first, y = it.first.second;
    new_dist[id_s][id_p] = new_dist[id_p][id_s] = dist[x][y];
  }
}

vector<vector<int>> memo;

int solve(int v, int mask){
  if(mask == 0) return new_dist[v][base];
  int& ans = memo[v][mask];
  if(ans != -1) return ans;
  ans = oo;
  for(int i = 0; i < base ; ++i){
    if(i == v) continue;
    if(!(mask & (1<<i))) continue;
    ans = min(ans, new_dist[v][i] + solve(i, mask-(1<<i)));
  }
  return ans;
}

int main(){
    fastio();
    while(cin >> n >> m >> k && n + m + k){
        idxp = 0;
        counterP.clear();
        grid.resize(n);
        for(int i = 0, cnt = 0; i < n ; ++i){
            cin >> grid[i];
            for(int j = 0; j < m ; ++j) {
                if(grid[i][j] == 'C') posi = i, posj = j;
                if(grid[i][j] == 'P') counterP[{i,j}] = idxp++;
            }
        }
        base = idxp++;
        counterP[{posi, posj}] = base;
        
        new_dist.assign(idxp, vector<int>(idxp, 0));
        for(auto x : counterP){
          bfs(x.first.first, x.first.second);
        }
        memo.assign(idxp,vector<int>(1<<k, -1));
        cout << solve(base, (1<<k)-1) << '\n';
    }

    return 0;
}