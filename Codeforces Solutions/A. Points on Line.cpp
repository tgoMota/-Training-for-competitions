//https://codeforces.com/contest/251/problem/A
//A. Points on Line
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9+7;
typedef long long ll;
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    ll n, d;
    cin >> n >> d;
    vector<ll> v(n);
    for(ll& x :  v) cin >> x;
    ll ans = 0LL;
    for(int i = 0; i < n ; ++i){
      int k = upper_bound(v.begin(), v.end(), v[i]+d) - v.begin()-i;
      ans+=(k-1)*1LL*(k-2)/2LL;
    }
 
    cout << ans << '\n';
    return 0;
}