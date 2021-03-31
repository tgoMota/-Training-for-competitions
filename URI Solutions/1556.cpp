//https://www.urionlinejudge.com.br/judge/pt/problems/view/1556
//URI 1556 - Removendo Letras
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
set<string> s;
string line;
void back(int idx, string cur){
  if(s.count(cur)) return;
  if(idx == (int)line.size()){
    s.insert(cur);
    return;
  }
  back(idx+1, cur+line[idx]);
  back(idx+1, cur);
}
int main(){
    fastio();
    while(cin >> line){
      s.clear();
      back(0, "");
      for(string x : s){
        if(x != "") cout << x << '\n';
      }
      cout << '\n';
    }
    return 0;
}

