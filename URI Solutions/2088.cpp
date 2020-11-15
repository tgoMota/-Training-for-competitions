//https://www.urionlinejudge.com.br/judge/pt/problems/view/2088
//URI 2088 - Combate à Dengue
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef pair<int,int> ii;
vector<ii> points;
vector<vector<int>> dist;
vector<vector<double>> memo;

int distP(ii& a, ii& b){
  return (b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second);
}

double solve(int idx, int mask, const int N){
  if(mask == 0 && idx == 0) return 0.0;
  if(mask == 0) return 99999;
  double& ans = memo[idx][mask];
  if(ans != -1) return ans;
  ans = 99999;
  for(int i = 0; i < N ; ++i){
    if(i == idx) continue;
    if(mask & (1<<i)) ans = min(ans, (double)sqrt(dist[idx][i])+solve(i, mask^(1<<i), N));
  }
  return ans;
}

int main(){
  int n;
  while(scanf("%d", &n) && n){
    points.assign(++n, {0,0});
    int mask = (1<<n)-1;
    memo.assign(n+1, vector<double>(mask+1, double(-1)));
    scanf("%d%d", &points[0].first, &points[0].second);
    for(int i = 1; i < n ; ++i) scanf("%d%d", &points[i].first, &points[i].second);
    dist.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n ; ++i){
      for(int j = 0; j < n ; ++j){
        dist[i][j] = distP(points[i], points[j]);
      }
    }
    printf("%.2lf\n", solve(0,mask,n));
  }
  
  return 0;
}