//https://www.urionlinejudge.com.br/judge/pt/problems/view/1278
//URI 1278 - Justificador II
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
void removeDuplicatedSpaces(string& x){
  string ans = "";
  const int N = (int)x.size();
  int i;
  for(i = 0; x[i] == ' ' ; ++i){}
  for(; i < N ; ++i){
    if(x[i] == ' ' && ans.back() == ' ') continue;
    ans += x[i];
  }
  if(ans.back() == ' ') ans.pop_back();
  x = ans;
}
int main(){
    fastio();
    int n;
    int t = 0;
    while(cin >> n && n){
      if(t++) cout << '\n';
      cin.ignore();
      vector<string> lines(n);
      int mxsize = 0;
      for(int i = 0; i < n ; ++i){
        getline(cin, lines[i]);
        removeDuplicatedSpaces(lines[i]);
        mxsize = max(mxsize,(int)lines[i].size());
      }
      
      for(int i = 0; i < n ; ++i){
        const int M  = (int)lines[i].size();
        lines[i].insert(lines[i].begin(),mxsize-M ,' ');
      }

      for(string& line : lines) cout << line << '\n';
    }
    return 0;
}

