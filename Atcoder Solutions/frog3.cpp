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
struct line{
  ll a, b; //ax + b
  line(){};
  line(ll _a, ll _b){
    a = _a;
    b = _b;
  }

  ll intersect(line other){
   return (other.b - b + a - other.a -1)/(a - other.a); 
  }

  ll val(ll x){
    return a*x + b;
  }
};
struct cht{
  deque<pair<line,ll>> dq;
  cht(){};
  void insert(ll slope, ll c){
    //trace(slope, c);
    line new_line(slope, c);
    while((int)dq.size() > 1 && dq.back().second >= dq.back().first.intersect(new_line)){
      dq.pop_back();
    }
    if(dq.empty()) {
      dq.emplace_back(new_line, 0);
      return;
    }
    dq.emplace_back(new_line, dq.back().first.intersect(new_line));
  }

  ll query(ll x){
    while((int)dq.size() > 1 && dq[1].second <= x) {
      dq.pop_front();
    }
    return dq[0].first.val(x);
  }
};

int main(){
  fastio();
  ll n, c;
  cin >> n >> c;
  vector<ll> dp(n);
  cht ch;
  for(int i = 0; i < n ; ++i){
    ll a;
    cin >> a;
    if(i == 0) ch.insert(-2*a,a*a);
    else{
      dp[i] = ch.query(a)+a*a+c;
      ch.insert(-2*a, dp[i]+a*a);
    }
  }

  cout << dp[n-1] << '\n';
  return 0;
}
