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
struct ret{
  ll x, y, c;
  ret(){}
  ret(ll _x, ll _y, ll _c){
    x = _x;
    y = _y;
    c = _c;
  }

  ll area(){
    return x*y;
  }
};

vector<ret> v;
vector<ll> dp;
double slope(int i,int j){
  //double m = (double)(dp[i]-dp[j])/(v[i].x-v[j].x);
  //trace(v[i].x, dp[i], v[j].x, dp[j], m);
  
  return (double)(dp[i]-dp[j])/(v[i].x-v[j].x);
}

ll val(int i, int j){
  return dp[j] + v[i].area() - v[i].c - v[j].x*v[i].y;
}
struct CH{
  CH(){};
  deque<int> dq;

  int query(int i){
    while((int)dq.size() > 1 && val(i,dq[0]) < val(i, dq[1])){
      dq.pop_front();
    }
    //if(val(i,0) > val(i,dq.front())) return 0;
    return dq.front();
  }

  void insert(int i){
    while((int)dq.size() > 1 && slope(dq.back(), dq[(int)dq.size()-2]) < slope(i, dq.back())) {
      trace("POP_BACK", dq.back());
      dq.pop_back();
    }
    dq.push_back(i);
  }
};

int main(){
  fastio();
  int n;
  cin >> n;
  v.emplace_back(0,0,0);
  for(int i = 0; i < n ; ++i){
    ll x, y, c;
    cin >> x >> y >> c;
    v.emplace_back(x,y,c);
  }
  sort(v.begin(), v.end(), [&](ret& a, ret& b){
    return a.x < b.x;
  });
  CH ch;
  ch.insert(0);
  dp.assign(n+1, 0LL);
  ll ans = -ooLL;
  for(int i = 1; i <= n ; ++i){
    dp[i] = val(i,ch.query(i));
    ch.insert(i);
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}
