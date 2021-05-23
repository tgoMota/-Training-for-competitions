//https://www.urionlinejudge.com.br/judge/pt/problems/view/1470
//URI 1470 - Máquina Dobradora
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
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
int n1, n2;
vector<ll> in, out;

vector<ll> cut(int pos, vector<ll> tmp){
  vector<ll> ans;
  int i, j;
  for(i = pos, j = pos+1; i >= 0 && j < (int)tmp.size() ; --i, ++j){
    ans.push_back(tmp[i]+tmp[j]);
  }
  for(; j < (int)tmp.size() ; ++j){
    ans.push_back(tmp[j]);
  }
  for(; i >= 0 ; --i){
    ans.push_back(tmp[i]);
  }
  return ans;
}

vector<ll> rev(vector<ll> tmp){
  reverse(tmp.begin(), tmp.end());
  return tmp;
}

bool solve(vector<ll> tmp){
  if(tmp == out || rev(tmp) == out) return true;
  if((int)tmp.size() <= (int)out.size()) return false;
  for(int i = 0; i < (int)tmp.size()-1 ; ++i){
    if(solve(cut(i, tmp))) return true;
  }
  return false;
}

int main(){
    fastio();
    int t;
    while(cin >> n1){
      in.resize(n1);
      for(ll& x : in) cin >> x;
      cin >> n2;
      out.resize(n2);
      for(ll& x: out) cin >> x;
      bool ok = solve(in);
      cout << (ok ? "S" : "N") << '\n';
    }
    return 0;
}
