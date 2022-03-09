//https://codeforces.com/problemset/problem/550/A
//A. Two Substrings
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
    string s;
    cin >> s;
    int pos_left = -1;
    const int N = (int)s.size();
    for(int i = 0; i < N-1; ++i){
      if(s.substr(i,2) == "AB"){
        pos_left = i+2;
        break;
      }
    }
    bool ok_left = false;
    if(pos_left != -1){
      for(int i = pos_left; i < N-1 ; ++i){
        if(s.substr(i,2) == "BA"){
          ok_left = true;
          break;
        }
      }
    }

    if(ok_left){
      cout << "YES\n";
      return 0;
    }
    pos_left = -1;
    for(int i = 0; i < N-1; ++i){
      if(s.substr(i,2) == "BA"){
        pos_left = i+2;
        break;
      }
    }
    if(pos_left != -1){
      for(int i = pos_left; i < N-1 ; ++i){
        if(s.substr(i,2) == "AB"){
          ok_left = true;
          break;
        }
      }
    }
    cout << (ok_left ? "YES" : "NO") << '\n';

    return 0;
}
