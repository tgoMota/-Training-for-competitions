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
int idx[] = {0,0,0};
int n[3];
vector<vector<int>> v;
pair<int,int> pk(){
  vector<int> temp = {0,1,2};
  sort(temp.begin(), temp.end(), [&](int a, int b){
    return (n[a]-idx[a]) > (n[b]-idx[b]);
  });
  return make_pair(temp[0], temp[1]);
}

bool ok(){
  int cnt = (n[0]-idx[0] > 0) + (n[1]-idx[1] > 0) + (n[2]-idx[2] > 0);
  return cnt > 1;
}

int main(){
    for(int i = 0; i < 3 ; ++i) scanf("%d", &n[i]);
    for(int i = 0; i < 3 ; ++i){
      vector<int> temp;
      for(int j = 0; j < n[i] ; ++j){
        int a;
        scanf("%d", &a);
        temp.push_back(a);
      }
      v.push_back(temp);
    }


    while(ok()){
      pair<int,int> p = pk();
      int a = p.first, b = p.second;
      int idxa = idx[a], idxb = idx[b];
      trace(a, b, idxa, idxb, v[a][idxa], v[b][idxb]);
      v[a][idxa] = v[a][idxa] - v[b][idxb];
      idx[b]++;
    }

    if(n[0]-idx[0] > 0) printf("%d\n", v[0].back());
    else if(n[1]-idx[1] > 0) printf("%d\n", v[1].back());
    else printf("%d\n", v[2].back());


    return 0;
}
