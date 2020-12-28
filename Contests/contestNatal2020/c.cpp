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
 
int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int,string>> v;
    for(int i = 0; i < n ; ++i){
      string a;
      cin >> a;
      int age;
      cin >> age;
      v.push_back({age,a});
    }

    sort(v.begin(), v.end(), [&](pair<int,string>& a, pair<int,string>& b){
      if(a.first > b.first) return true;
      else if(a.first < b.first) return false;
      else{
        bool r = lexicographical_compare(a.second.begin(), a.second.end(), b.second.begin(), b.second.end());
        if(r) return true;
        else return false;
      }
    });

    int tot = n/3;
    vector<vector<pair<int,string>>> v2(tot);
    for(int i = 0; i < (int)v.size() ; ++i){
      int team = i%tot;
      v2[team].push_back(v[i]);
    }

    for(int i = 0; i < tot ; ++i){
      printf("Time %d\n", i+1);
      for(int j = 0; j < (int)v2[i].size() ; ++j){
        printf("%s %d\n", v2[i][j].second.c_str(), v2[i][j].first);
      }
      printf("\n");
    }
      
    return 0;
}
