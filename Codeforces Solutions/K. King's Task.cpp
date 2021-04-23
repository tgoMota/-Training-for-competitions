//https://codeforces.com/problemset/problem/1510/K
//K. King's Task
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
    int n;
    cin >> n;
    vector<int> v(2*n), tmp;
    for(int &x : v) cin >> x;
    tmp = v;
    int ans1 = 0;
    for(int i = 0; i < 2*n ; ++i){
      if(is_sorted(v.begin(), v.end())) break;
      if(i%2){
        for(int j = 0; j < n ; ++j){
          swap(v[j], v[j+n]);
        }
      }else{
        for(int j = 0; j < 2*n-1 ; j+=2){
          swap(v[j], v[j+1]);
        }
      }
      ans1++;
    }
    if(!is_sorted(v.begin(),v.end())) ans1 = oo;
    int ans2 = 0;
    v = tmp;
    for(int i = 1; i <= 2*n ; ++i){
      if(is_sorted(v.begin(), v.end())) break;
      if(i%2){
        for(int j = 0; j < n ; ++j){
          swap(v[j], v[j+n]);
        }
      }else{
        for(int j = 0; j < 2*n-1 ; j+=2){
          swap(v[j], v[j+1]);
        }
      }
      ans2++;
    }
    if(!is_sorted(v.begin(),v.end())) ans2 = oo;
    int ans = min(ans1, ans2);
    cout << (ans == oo ? -1 : ans) << '\n';
    return 0;
}
