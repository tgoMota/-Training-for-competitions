//https://www.urionlinejudge.com.br/judge/pt/problems/view/1474
//URI 1474 - Ônibus
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
const int mod = 1000000;
typedef long long ll;
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
ll N, K, L;
typedef vector<vector<ll>> mat;
mat identity(const int n){
  mat m(n, vector<ll>(n,0LL));
  for(int i = 0; i < n ; ++i) m[i][i] = 1LL;
  return m;
}
mat mul(mat& a, mat& b){
  mat c((int)a.size(), vector<ll>((int)b[0].size(), 0LL));
  for(int i = 0; i < (int)a.size() ;  ++i){
    for(int j = 0; j < (int)b[0].size() ; ++j){
      for(int k = 0; k < (int)b.size() ; ++k){
        c[i][j] += (a[i][k]%mod)*(b[k][j]%mod)%mod;
        c[i][j]%=mod;
      }
    }
  }
  return c;
}

mat powMat(mat a, ll n){
  if(n == 0) return identity((int)a.size());
  mat b = powMat(a, n/2);
  b = mul(b,b);
  if(n%2) b = mul(b,a);
  return b;
}

int main(){
    fastio();
    mat a, b, c, d;
    while(cin >> N  >> K >> L){
      //recurrence: f(n) = K*f(n-1) + L*f(n-2)
      N/=5LL;
      K%=mod;
      L%=mod;
      a = {{1, K, 0}};
      b = {{0,L,1},{1,K,0},{0,0,0}};
      d = powMat(b, N-1);
      mat c = mul(a,d);
      cout << setfill('0') << setw(6) << c[0][1] << '\n';
    }
    return 0;
}


