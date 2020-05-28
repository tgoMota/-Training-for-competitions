#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 

 ll solve(vector<ll>& arr, int k) { 
    const int n = arr.size();
    if (n < k) return 0LL;
  
    int start = 0, end = k - 1; 
    ll sum = 0LL;
  
    for (int i = 0; i < k; i++) { 
        sum += arr[i]; 
    } 
  
    ll ans = sum; 
  
    for (int i = k; i < n + k; i++) { 
  
        sum += arr[i % n] - arr[(i - k) % n]; 
  
        if (sum > ans) { 
            ans = sum; 
            start = (i - k + 1) % n; 
            end = i % n; 
        } 
    } 
  
    return ans;
} 

int main(){
    int t = 1;
    for(int ti = 1; ti <= t ; ++ti){
        int n, d;
        scanf("%d%d", &n, &d);
        vector<ll> v(n);
        vector<ll> v2;
        for(int i = 0; i < n ; ++i){
            scanf("%lld", &v[i]);
            for(ll j = 1LL; j <= v[i] ; ++j) v2.push_back(j);
        }

        printf("%lld\n", solve(v2, d));

    }
    return 0;
}