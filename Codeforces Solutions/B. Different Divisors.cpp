//https://codeforces.com/contest/1474/problem/B
//B. Different Divisors
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
vector<int> primes;

void sieve(int up){
  vector<bool> prime(up+1, true);
  prime[0] = prime[1] = false;
  for(int i = 2; i <= up ; ++i){
    if(!prime[i]) continue;
    for(int j = i*i; j <= up ; j += i){
      prime[j] = 0;
    }
    primes.push_back(i);
  }
}
int main(){
    int t;
    scanf("%d", &t);
    sieve(30000);
    for(int ti = 1; ti <= t ; ++ti){
        int d;
        scanf("%d", &d);
        int first = lower_bound(primes.begin(), primes.end(), d+1) - primes.begin();
        int second = lower_bound(primes.begin(), primes.end(), primes[first]+d)-primes.begin();
        printf("%lld\n", primes[first]*1LL*primes[second]);
    }
    return 0;
}
