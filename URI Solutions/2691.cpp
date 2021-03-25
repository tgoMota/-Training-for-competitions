//https://www.urionlinejudge.com.br/judge/pt/problems/view/2691
//URI 2691 - O Matemático
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
int main(){
   // fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int a, b;
        scanf("%dx%d", &a, &b);
        for(int i = 5; i <= 10; ++i){
          if(a != b) printf("%d x %d = %d && %d x %d = %d\n", a, i, a*i, b, i, b*i);
          else printf("%d x %d = %d\n", a, i, a*i);
        }
    }
    return 0;
}
