//https://www.urionlinejudge.com.br/judge/pt/problems/view/1804
//URI 1804 - Precisa-se de Matemáticos em Marte
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
//CHECK THE LIMITS, PLEASE
vector<int> v, f;
struct fen{
  fen(const int n){
    f.assign(n+1, 0);
    for(int i = 0; i < n ; ++i) update(i,v[i], n);
  };
  void update(int idx, int val, const int n){
    idx++;
    while(idx <= n){
      f[idx] += val;
      idx += idx & (-idx);
    }
  }

  int query(int idx, const int n){
    idx++;
    int sum = 0;
    while(idx>0){
      sum += f[idx];
      idx -= idx & (-idx);
    }
    return sum;
  }
};
int main(){
    fastio();
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n ; ++i) cin >> v[i];
    fen Fen(n);
    char c;
    int b;
    while(cin >> c  >> b && !cin.eof()){
      b--;
      if(c == '?') cout << Fen.query(b-1,n) << '\n';
      else{
        Fen.update(b,-v[b],n);
        v[b] = 0;
      }
    }
    return 0;
}
