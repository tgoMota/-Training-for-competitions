#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max2(ll a, ll b){
    if(a > b) return a;
    else return b;
}
int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n ; ++i) scanf("%lld", &v[i]);
    printf("%lld\n", max2((ll)v[0]*v[1]*v[n-1], (ll)v[n-1]*v[n-2]*v[n-3]));
    return 0;
}