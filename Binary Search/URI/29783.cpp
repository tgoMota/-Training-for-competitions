//https://www.urionlinejudge.com.br/judge/pt/problems/view/2973
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,c,t, v[100010];

bool can(ll mid){
    ll comp = 1, saco = 0, maxP = t*mid;
    for(ll s = 1; s <= n ; ++s){
        ll pipocas = v[s] - v[saco];
        if(pipocas > maxP || comp > c) return false;
        if(s < n && (v[s+1] - v[saco] > maxP)){
            comp++;
            saco = s;
        }
    }
    return true;
}

int main(){
    cin >> n >> c >> t;
    for(ll i = 1; i <= n ; ++i){
        cin >> v[i];
        v[i] += v[i-1];
    }

    ll hi = 1e9+10, lo =0;
    for(ll i = 1; i <= 35 ; ++i){
        ll mid = (hi + lo) >> 1;
        if(can(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo << endl;

return 0;
