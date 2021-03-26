//https://www.urionlinejudge.com.br/judge/pt/problems/view/1254
//URI 1254 - Substituição de Tag
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
    string tag, line;
    int change;
    while(getline(cin, tag)){
      cin >> change;
      cin.ignore();
      getline(cin, line);
      string line2 = line;
      const int M = (int)tag.size();
      const int N = (int)line.size();
      bool tagged = false;
      for(char& c : line){
        if(isalpha(c)) c = tolower(c);
      }
      for(char& c : tag){
        if(isalpha(c)) c= tolower(c);
      }
      //trace(line, tag);
      for(int i = 0; i < N ; ++i){
        if(line[i] == '<') tagged = true;
        if(line[i] == '>') tagged = false;
        if(i+M-1 < N && tagged && line.substr(i, M) == tag){
          cout << change;
          i+=M-1;
          continue;
        }
        cout << line2[i];
      }
      cout << '\n';
    }
    return 0;
}

