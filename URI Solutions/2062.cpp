//https://www.urionlinejudge.com.br/judge/pt/problems/view/2062
//URI 2062 OBI URI
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
    fastio();
    int n;
    cin >> n;
    for(int i = 0; i < n ; ++i){
      string s;
      cin >> s;
      if(i) cout << " ";
      if((int)s.size() != 3){
        cout << s;
        continue;
      }
      if(s[0] == 'U' && s[1] == 'R') cout << "URI";
      else if(s[0] == 'O' && s[1] == 'B') cout << "OBI";
      else cout << s;
    }
    cout << '\n';
    return 0;
}

