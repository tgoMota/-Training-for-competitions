//https://www.urionlinejudge.com.br/judge/pt/problems/view/2310
//URI 2310 - Voleibol
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
    //fastio();
    int n;
    cin >> n;
    vector<int> a(3, 0), b(3, 0);
    for(int i = 0; i < n ; ++i){
      string s;
      cin >> s;
      int ka, kb, kc;
      cin >> ka >> kb >> kc;
      a[0] += ka;
      a[1] += kb;
      a[2] += kc;
      cin >> ka >> kb >> kc;
      b[0] += ka;
      b[1] += kb;
      b[2] += kc;
    }
    printf("Pontos de Saque: %.2lf %%.\n", (b[0]*100)/(double)a[0]);
    printf("Pontos de Bloqueio: %.2lf %%.\n", (b[1]*100)/(double)a[1]);
    printf("Pontos de Ataque: %.2lf %%.\n", (b[2]*100)/(double)a[2]);
    return 0;
}

