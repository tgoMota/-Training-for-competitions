//https://www.urionlinejudge.com.br/judge/pt/problems/view/1202
//URI 1202 - Festival das Noites Brancas
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

int fibmod(int x){
  if(x < 2) return x;
  int a = 0, b = 1, c = 0;
  for(int i = 2; i <= x ; ++i){
    c = a + b;
    c %= 1000;
    a = b;
    b = c;
  }
  return c;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        string s;
        cin >> s;
        const int sz = (int)s.size();
        int num = 0;
        for(int i = 0; i < sz ; ++i){
          num *= 2;
          num += (s[i]-'0');
          num %= 1500;
        }

        printf("%03d\n", fibmod(num));
    }
    return 0;
}
