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
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    vector<bool> latin(26,false);
    for(int i = 0; i < k ; ++i){
      char c;
      scanf(" %c", &c);
      latin[c-'a'] = true;
    }

    vector<int> dp(n+1, 0);
    ll ans = 0LL;
    for(int i = 1; i <= n ; ++i){
      char ch = s[i-1]-'a';
      if(!latin[ch]) continue;
      dp[i] += dp[i-1]+1;
      ans += (ll)dp[i];
    }

    printf("%lld\n", ans);


    return 0;
}
