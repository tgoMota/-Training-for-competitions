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
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b){
          cout << "Yes\n";
          continue;
        }
        map<char, int> mp;
        for(char c : a) mp[c]++;

        map<char,int> mp2;
        for(char c : b){
          mp2[c]++;
        }
        int dif = 0;
        int mx = 0;
        for(char c : b){
          dif += abs(mp2[c]-mp[c]);
          if(mp[c]-mp2[c] > mx){
            mx = mp[c]-mp2[c];
          }
        }

        if(mx < m){
          cout << "No\n";
          continue;
        }

    }
    return 0;
}
