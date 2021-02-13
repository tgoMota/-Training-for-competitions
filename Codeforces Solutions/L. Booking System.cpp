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
//CHECK THE CONSTRAINTS, PLEASE
vector<pair<ii, int>> requests;
vector<ii> tables;
int main(){
    int n, k;
    scanf("%d", &n);
    requests.resize(n);
    for(int i = 0; i < n ; ++i){
      int a, b;
      scanf("%d%d", &a, &b);
      requests[i] = make_pair(make_pair(b,a), i);
    }
    scanf("%d", &k);
    tables.resize(k);
    for(int i = 0; i < k ; ++i){
      int a;
      scanf("%d", &a);
      tables[i] = {a, i};
    } 

    sort(requests.begin(), requests.end(), [](pair<ii,int>& a, pair<ii,int>& b){
      return a.first.first > b.first.first;
    });

    sort(tables.begin(), tables.end());
    vector<int> match(k+1, -1);
    int ans = 0;
    ll sum = 0LL;
    for(int i = 0; i < n ; ++i){
      auto req = requests[i];
      for(int j = 0; j < k ; ++j){
        auto tab = tables[j];
        if(match[tab.second] != -1) continue;
        if(req.first.second <= tab.first){
          match[tab.second] = req.second;
          ans++;
          sum += req.first.first;
          break;
        }
      }
    }

    printf("%d %lld\n", ans, sum);
    for(int i = 0; i < k ; ++i){
      auto tab = tables[i];
      if(match[tab.second] != -1){
        printf("%d %d\n", match[tab.second]+1, tab.second+1);
      }
    }

    return 0;
}
