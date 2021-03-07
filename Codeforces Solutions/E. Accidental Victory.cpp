//https://codeforces.com/problemset/problem/1490/E
//E. Accidental Victory
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
int n;
vector<ii> v;
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> n;
        v.resize(n);
        for(int i = 0; i < n ; ++i){
          cin >> v[i].first;
          v[i].second = i;
        }

        sort(v.begin(), v.end());
        vector<ll> pref;
        ll sum = 0LL;
        for(int i = 0; i < n ; ++i){
          sum += v[i].first;
          pref.push_back(sum);
        }
        vector<int> ans;
        for(int i = n-2; i>=0; --i){
          if(pref[i] < v[i+1].first) break;
          ans.push_back(v[i].second);
        }
        ans.push_back(v[n-1].second);
        sort(ans.begin(), ans.end());
        cout << (int)ans.size() << '\n';
        for(int x : ans) cout << x+1 << " ";
        cout << '\n';
    }
    return 0;
}
