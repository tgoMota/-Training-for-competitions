//https://codeforces.com/contest/1579/problem/D
//D. Productive Meeting
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
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        priority_queue<ii> pq;
        for(int i = 0; i < n ; ++i){
          int x;
          cin >> x;
          if(x) pq.push({x, i+1});
        }

        vector<ii> ans;
        while((int)pq.size() > 1){
          int a = pq.top().first;
          int idx_a = pq.top().second;
          pq.pop();
          int b = pq.top().first;
          int idx_b = pq.top().second;
          pq.pop();
          ans.push_back({idx_a, idx_b});
          a--, b--;
          if(a) pq.push({a,idx_a});
          if(b) pq.push({b,idx_b});
        }

        cout << (int)ans.size() << '\n';
        for(ii& x : ans){
          cout << x.first << ' ' << x.second << '\n';
        }
    }
    return 0;
}
