//https://www.urionlinejudge.com.br/judge/pt/problems/view/2108
//URI 2108 - Contando Caracters
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
    string line;
    pair<int, string> mxWord = {0,""};
    while(getline(cin, line) && line != "0"){
      int cnt = 0;
      const int N = (int)line.size();
      bool first = true;
      string word = "";
      for(int i = 0; i < N ; ++i){
        if(line[i] == ' '){
          if(cnt > mxWord.first) mxWord = {cnt, word};
          if(first) cout << cnt;
          else cout << '-' << cnt;
          first = false;
          cnt = 0;
          word = "";
        }else{
          word += line[i];
          cnt++;
        }
      }
      if(cnt >= mxWord.first) mxWord = {cnt, word};
      if(first) cout << cnt << '\n';
      else cout << '-' << cnt << '\n';
    }

    cout << '\n';
    cout << "The biggest word: " << mxWord.second << '\n';
    return 0;
}

