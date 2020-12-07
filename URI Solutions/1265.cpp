//https://www.urionlinejudge.com.br/judge/pt/problems/view/1265
//URI1265 - DJ da Computação
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

int n, q;
vector<string> v;

int calc(int query){
  if(query <= n) return query-1;
  int category = 1, sizeCategory = n, totalChars = sizeCategory*category;
  //A B C AA AB AC BA BB BC CA CB CC AAA AAB AAC ABA ABB ABC..
  while(query-totalChars>0){
    query-=totalChars;
    sizeCategory *= n;
    totalChars = (++category)*sizeCategory;
  }
  //trace(query, totalChars, sizeCategory, category);
  //A B C [AA AB AC BA BB BC CA CB CC] AAA AAB AAC ABA ABB ABC..
  int groups = sizeCategory/n;
  int lenWord = category;
  int ans = 0, cnt = 0;
  query--;
  while(query > 0){
    totalChars/=n;
    ans = query/totalChars;
    query %= totalChars;
    if(query % lenWord == cnt++) break;
  }
  return ans;
}

int main(){
    fastio();
    while(cin >> n >> q && n+q){
      v.clear();
      for(int i = 0; i < n ; ++i){
        string a;
        cin >> a;
        v.push_back(a);
      }

      for(int i = 0; i < q ; ++i){
        int a;
        cin >> a;
        cout << v[calc(a)].c_str() << '\n';
      }
      cout << '\n';
    }
    return 0;
}