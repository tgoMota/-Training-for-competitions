//https://www.urionlinejudge.com.br/judge/pt/problems/view/1119
//URI 1119 - A Fila de Desempregados
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
    int t;
    int n, k, m;
    while(cin >> n >> k >> m  && (n+k+m)){
      list<int> circle;
      for(int i = 1; i <= n ; ++i) circle.push_back(i);
      auto a = circle.begin(), b = prev(circle.end());

      auto getNext = [&](list<int> :: iterator p){
        auto nextPerson = next(p);
        if(nextPerson == circle.end()) return circle.begin();
        return nextPerson;
      };
      auto getPrev = [&](list<int> :: iterator p){
        if(p == circle.begin()) return prev(circle.end());
        return prev(p);
      };

      vector<ii> ans;
      while(!circle.empty()){
        for(int i = 0; i < k-1 ; ++i) a = getNext(a);
        for(int i = 0; i < m-1 ; ++i) b = getPrev(b);
        
        ans.push_back({*a,*b});
        if(a == b){
          a = getNext(a);
          auto tmp = b;
          b = getPrev(b);
          circle.erase(tmp);
        }else{
          auto tmp_a = a;
          a = getNext(a);
          circle.erase(tmp_a);
          auto tmp_b = b;
          if(a == b) a = getNext(a);
          b = getPrev(b);
          circle.erase(tmp_b);
        }
      }

      const int N = (int)ans.size();
      for(int i = 0; i < N ; ++i){
        if(i) cout << ',';
        if(ans[i].first == ans[i].second) cout << setw(3) << ans[i].first;
        else cout << setw(3) << ans[i].first << setw(3) << ans[i].second;
      }
      cout <<  '\n';
    }
    return 0;
}
