//https://codeforces.com/contest/1474/problem/C
//C. Array Destruction
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
//CHECK THE LIMITS, PLEASE
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<int> v(2*n);
        int mx = 0;
        for(int i = 0; i < 2*n ; ++i){
          scanf("%d", &v[i]);
          if(v[i] > v[mx]) mx = i;
        }

        vector<ii> va;
        for(int i = 0; i < 2*n ; ++i){
          multiset<int> ms;
          int x = v[mx];
          for(int j = 0; j < 2*n ; ++j){
            if(j == i || j == mx) continue;
            ms.insert(v[j]);
          }
          bool ok = true;
          va.clear();
          va.push_back({v[mx], v[i]});
          while(!ms.empty()){
            int a = *ms.rbegin();
            ms.erase(ms.find(a));
            if(ms.find(x-a) == ms.end()){
              ok = false;
              break;
            }
            ms.erase(ms.find(x-a));
            va.push_back({a, x-a});
            x = a;
          }

          if(ok) break;
        }

        if((int)va.size() != n){
          printf("NO\n");
          continue;
        }
        printf("YES\n");
        printf("%d\n", va[0].first+va[0].second);
        for(ii& k : va) printf("%d %d\n", k.first, k.second);
    }
    return 0;
}
