#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
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
vector<int> primes;
vector<bool> isPrime;
void sieve(int n){
  isPrime.assign(n+1, true);
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i <= n ; ++i){
    if(isPrime[i]){
      primes.push_back(i);
      for(int j = i*i; j <= n ; j += i) isPrime[j] = false;
    }
  }
}
int main(){
    fastio();
    int n;
    cin >> n;
    sieve(n);
    int ans = 0;
    for(int i = 2; i <= n ; ++i){
      int cnt = 0;
      for(int x : primes){
        if(x > i || cnt > 2) break;
        if(i % x == 0) cnt++;
      }
      if(cnt == 2) ans++;
    }

    cout << ans << '\n';
    return 0;
}
