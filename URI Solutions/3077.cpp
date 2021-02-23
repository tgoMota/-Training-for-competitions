//https://www.urionlinejudge.com.br/judge/pt/problems/view/3077
//URI 3077 - Distribuindo Pequis
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
//CHECK THE LIMITS, PLEASE
int main(){
    fastio();
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    int sum = 0;
    for(int i = 0; i < n ; ++i){
      int a;
      cin >> a;
      dq.push_back(a);
      sum += a;
    }
    vector<int> ans(n, 0);
    for(int i = 0; i < n ; ++i){
      ans[i] += sum * (k/n);
    }
    for(int i = 0; i < k%n ; ++i){
      int t = 0;
      for(int x : dq) ans[t++]+=x;
      int a = dq.back();
      dq.pop_back();
      dq.push_front(a);
    }
    for(int i = 0; i < n ; ++i){
      cout << ans[i];
      if(i != n-1) cout << " ";
    }
    cout << '\n';
    return 0;
}
