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
map<int,int> freq;
vector<int> allfreq;
int fen[200005], n;

void add(int idx, int x){
  idx++;
  const int N = (int)allfreq.size();
  while(idx <= N){
    fen[idx]+=x;
    idx+= idx & (-idx);
  }
}

int query(int idx){
  idx++;
  const int N = (int)allfreq.size();
  int sum = 0;
  while(idx > 0){
    sum += fen[idx];
    idx -= idx&(-idx);
  }
  return sum;
}

void build(){
  memset(fen, 0x0, sizeof(fen));
  for(int i = 0; i < (int)allfreq.size() ; ++i){
    add(i, allfreq[i]);
  }
}

int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> n;
        vector<int> v(n);
        for(int& x : v){
          cin >> x;
          freq[x]++;
        }

        for(auto x : freq){
          allfreq.push_back(x.second);
        }

        sort(allfreq.begin(), allfreq.end());
        build();
        int ans = oo;
        const int N = (int)allfreq.size();
        for(int c = 1; c <= allfreq.back() ;  ++c){
          int pos = upper_bound(allfreq.begin(), allfreq.end(), i) - allfreq.begin();
          ans = min(ans, query(N-1)-query(pos-1));
        }
    }
    return 0;
}
