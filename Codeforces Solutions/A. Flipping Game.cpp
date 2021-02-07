//https://codeforces.com/contest/327/problem/A
//A. Flipping Game
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
int score(int val){
  return val == 1 ? -1 : 1;
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    int sum = 0;
    for(int& x : v) {
      scanf("%d", &x);
      sum += x==1;
    }
    int maxsum = sum, inisum = sum;
    for(int i = 0; i < n ; ++i){
      sum += score(v[i]);
      sum = max(sum, inisum);
      maxsum = max(maxsum, sum);
    }

    printf("%d\n", maxsum == inisum ? maxsum-1 : maxsum);
    return 0;
}
