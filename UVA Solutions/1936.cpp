//https://www.urionlinejudge.com.br/judge/pt/problems/view/1936
//URI 1936 - Fatorial
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
int memo[100050], f[105];

int fat(int n){
  if(n <= 1) return 1;
  int& ans = f[n];
  if(ans != -1) return ans;
  return ans = n*fat(n-1);
}

int solve(int n){
  if(n == 0) return 0;
  if(n < 0) return oo;
  int& ans = memo[n];
  if(ans != -1) return ans;
  ans = oo;
  for(int i = 1; i <= n ; ++i){
    const int newVal = n-fat(i);
    if(newVal < 0) break;
    ans = min(ans, solve(newVal)+1);
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);
  memset(f, -1, sizeof(f));
  memset(memo, -1, sizeof(memo));
  printf("%d\n", solve(n));
  
  return 0;
}