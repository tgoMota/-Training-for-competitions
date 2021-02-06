#include <bits/stdc++.h>
using namespace std;
const int NAX = 505;
int grid[NAX][NAX];
bool ok(int val, int a, int b){
  return val >= a && val <= b;
}
int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) && n+m){
      for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m ; ++j){
          scanf("%d", &grid[i][j]);
        }
      }

      int q;
      scanf("%d", &q);
      while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        int ans = 0;
        printf("%d\n", ans);
      }
      printf("-\n");
    }
    return 0;
}
