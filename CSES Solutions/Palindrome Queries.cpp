#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(),(x).end()
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
const int mod = 1e9+9;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
struct FenwickTree{
    vector<ll> tree; //vector to represent our fenwick
    int N; //number of elements
    FenwickTree(const int n){ //just resizing the vector to N+1 position, because this fenwick tree is 1-indexed (1..N)
        N = n;
        tree.assign(n+1, 0);
    }
    //idx & (-idx) is the least significant bit
    void update(int idx, ll val){ //increases the value at index idx in val units  //takes O(logN) time complexity
        idx++; //increasing one unit because our original vector is 0-indexed (0..N-1), so the idx would be 0
        while(idx <= N){
            tree[idx] = (tree[idx] + val + mod)%mod;
            idx += idx & (-idx); //moving up in the tree
        }
    }

    ll get(int idx){ //get the accumulated sum up to index idx   //takes O(logN) time complexity
        idx++; //increasing one unit because our original vector is 0-indexed (0..N-1), so the idx would be 0
        ll sum = 0;
        while(idx>0){
            sum = (sum + tree[idx])%mod;
            idx -= idx & (-idx); 
        }
        return sum;
    }

    void build(vector<int>& v){ 
        for(int i = 0; i < (int)v.size() ; ++i) update(i,v[i]);
    }
};
const int nax = 200005;
FenwickTree fenLeft(nax), fenRight(nax);

ll mod_pow(ll a, ll b, ll m){
 a%=m;
 ll ans = 1LL;
 while(b){
  if(b&1) ans = ans * a % m;
  a = a*a % m;
  b >>= 1;
 }
 return ans;
}

void compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    ll p_pow = 1;
    const int n = (int)s.size();
    for (int i = 0; i < n ; ++i) {
      char c = s[i];
      ll cur = (c - 'a' + 1) * p_pow;
      fenLeft.update(i, cur);
      p_pow = (p_pow * p) % m;
    }
    
    p_pow = 1;
    for(int i = 0; i < n ; ++i){
      char c = s[n-i-1];
      ll cur = (c - 'a' + 1) * p_pow;
      fenRight.update(i, cur);
      p_pow = (p_pow * p) % m;
    }
}

int main(){
  fastio();
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  compute_hash(s);
  for(int i = 0; i < m ; ++i){
    int ty;
    cin >> ty;
    if(ty == 1){
      int p;
      char c;
      cin >> p >> c;
      p--;

      ll curLeft = (fenLeft.get(p) - fenLeft.get(p-1) + mod)%mod;
      ll new_val = (c-'a'+1)*mod_pow(31, p, mod);
      ll dif = new_val - curLeft;
      fenLeft.update(p, dif);

      ll curRight = (fenRight.get(n-p-1) - fenRight.get(n-p-2) + mod)%mod;
      ll new_val_r = (c-'a'+1)*mod_pow(31, n-p-1, mod);
      ll difR = new_val_r - curRight;
      fenRight.update(n-p-1, difR);

    }else{
      int l, r;
      cin >> l >> r;
      l--, r--;
      ll sum_left = (fenLeft.get(r) - fenLeft.get(l-1) + mod)%mod;
      ll pl = mod_pow(31, l, mod);
      ll md_left = mod_pow(pl, mod-2, mod);
      sum_left = (sum_left*md_left)%mod; //divididno por p^l

      ll sum_right = (fenRight.get(n-l-1) - fenRight.get(n-r-2) + mod)%mod;
      ll pr = mod_pow(31, n-r-1, mod);
      ll md_right = mod_pow(pr, mod-2, mod);
      sum_right = (sum_right*md_right)%mod;

      //trace(l, r, sum_left, sum_right);
      cout << (sum_left == sum_right ? "YES" : "NO") << '\n';
    }
  }
  return 0;
}
