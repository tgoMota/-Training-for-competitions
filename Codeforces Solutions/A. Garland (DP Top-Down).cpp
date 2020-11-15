//https://codeforces.com/contest/1286/problem/A
//A. Garland
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f;
vector<int> v;
 
int memo[2][101][55];
int solve(int last, int idx, int odd, const int N){
  if(odd < 0) return oo;
  if(idx == N) return odd == 0 ? 0 : oo;
  int& ans = memo[last][idx][odd];
  if(ans != -1) return ans;
  if(v[idx] != 0) return ans = solve(v[idx]%2, idx+1, odd, N) + ((v[idx]%2) != last);
  return ans = min(solve(1, idx+1, odd-1, N) + !last, solve(0, idx+1, odd, N) + last);
}
 
int main(){
  int n;
  scanf("%d", &n);
  v.assign(n, 0);
  int odd = n/2 + n%2;
  for(int& x : v) {
    scanf("%d", &x);
    odd -= x%2;
  }
  memset(memo, -1, sizeof(memo));
  printf("%d\n", min(solve(0, 0, odd, n), solve(1, 0, odd, n)));
  return 0;
}