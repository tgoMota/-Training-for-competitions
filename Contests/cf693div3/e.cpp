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
vector<pair<pair<ll,ll>,int>> vec;
vector<int> p;

int find(int u){
  return p[u] == u ? u : find(p[u]);
}

void merge(int u, int v){
  u = find(u);
  v = find(v);
  if(u == v) return;
  auto xu = vec[u].first;
  auto xv = vec[v].first;
  if(xu.first < xv.first && xu.second < xv.second) p[v] = u;
  else if(xu.first < xv.second && xu.second < xv.first) p[v] = u;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vec.clear();
        for(int i = 0; i < n ; ++i){
          int a, b;
          scanf("%d%d", &a, &b);
          vec.push_back({{a,b},i});
        }
        p.resize(n);
        for(int i = 0; i < n ; ++i) p[i] = i;

        // sort(vec.begin(), vec.end(), [](pair<pair<ll,ll>,int>& a, pair<pair<ll,ll>,int>& b){
        //   pair<ll,ll> xu = a.first, xv = b.first;
        //   if(xu.first < xv.first && xu.second < xv.second) return true;
        //   if(xu.first < xv.second && xu.second < xv.first) return true;
        //   return false;
        // });

        for(int i = 0; i < n ; ++i){
          for(int j = 0; j < n ; ++j){
            if(i == j) continue;
            merge(vec[i].second,vec[j].second);
          }
        }

        for(int i = 0; i < n ; ++i){
          printf("%d ", p[i] == i ? -1 : p[i]+1);
        }
        printf("\n");
    }
    return 0;
}