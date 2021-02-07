//https://codeforces.com/contest/466/problem/A
//A. Cheap Travel
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
const int NAX = 1005;
int memo[NAX];
int n, m, a, b;
int solve(int rest){
  if(rest <= 0) return 0;
  int& ans = memo[rest];
  if(ans != -1) return ans;
  return ans = min(b + solve(rest-m), a + solve(rest-1));
}

int main(){
    scanf("%d%d%d%d", &n, &m, &a, &b);
    memset(memo, -1, sizeof(memo));
    printf("%d\n", solve(n));
    return 0;
}
