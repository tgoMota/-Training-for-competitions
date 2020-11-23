//https://www.urionlinejudge.com.br/judge/pt/problems/view/2067
//URI 2067 - Jogo do Quadrado
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  int matrix[n][m];
  for(int i = 0; i < n ; ++i)
    for(int j = 0; j < m ; ++j) scanf("%d", &matrix[i][j]);
  
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
  int maxsquare = 0;
  for(int i = 1; i <= n ; ++i){
    for(int j = 1; j <= m ; ++j){
      if(!matrix[i-1][j-1]) continue;
      dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1;
      maxsquare = max(maxsquare, dp[i][j]);
    }
  }


  int q;
  scanf("%d", &q);
  for(int i = 0; i < q; ++i){
    int query;
    scanf("%d", &query);
    printf("%s\n", query <= maxsquare ? "yes" : "no");
  }


  return 0;
}