//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1620
//UVA 10679 - I Love Strings!!
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

struct kmp{
  string pat;
  vector<int> tmp;
  kmp(string _pat){
    pat = _pat;
    build();
  }

  void build(){
    const int N = (int)pat.size();
    tmp.assign(N+1, 0);
    tmp[0] = -1;
    int i = 0, j = -1;
    while(i < N){
      while(j >= 0 && pat[i] != pat[j]) j = tmp[j];
      i++, j++;
    }
  }

  bool search(string line){
    const int N = (int)line.size();
    const int M = (int)pat.size();
    int i = 0, j = 0;
    while(i < N){
      while(j >= 0 && line[i] != pat[j]) j = tmp[j];
      i++, j++;
      if(j == M) return true;
    }
    return false;
  }
};

int main(){
    fastio();
    int t;
    cin >> t;
    string line;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> line;
        int q;
        cin >> q;
        string pat;
        while(q--){
          cin >> pat;
          kmp km(pat);
          bool ok = km.search(line);
          cout << (ok ? "y" : "n") << '\n';
        }
    }
    return 0;
}

