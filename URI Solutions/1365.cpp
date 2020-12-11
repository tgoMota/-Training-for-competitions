//https://www.urionlinejudge.com.br/judge/pt/problems/view/1365
//URI 1365 - Procurando Assentos
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
vector<vector<int>> grid;
int main(){
    int r, c, k;
    while(scanf("%d%d%d", &r, &c, &k) && r+c+k){
      char rowLine[c+1];
      grid.assign(r+1, vector<int>(c+1));
      for(int i = 1; i <= r ; ++i){
        scanf("%s", &rowLine);
        for(int j = 1; j <= c ; ++j){
          grid[i][j] = (rowLine[j-1] == '.');
          grid[i][j]+= grid[i][j-1];
        }
      }


      int ans = oo;
      for(int col = 1; col <= c ; ++col){
        for(int colLimit = col; colLimit <= c ; ++colLimit){
            queue<int> sumRows;
            pair<int,int> sum = {0,0};
            for(int row = 1; row <= r ; ++row){
              sum.first += grid[row][colLimit] - grid[row][col-1];
              sumRows.push(grid[row][colLimit] - grid[row][col-1]);
              sum.second += colLimit-col+1;
              while(sum.first >= k){
                if(sum.second < ans) ans = sum.second;
                int valTop = sumRows.front();
                sumRows.pop();
                sum.first-=valTop;
                sum.second-=colLimit-col+1;
              }
            }
        }
      }

      printf("%d\n", ans);
    }
    return 0;
}
