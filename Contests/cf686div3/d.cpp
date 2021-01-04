#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        ll n;
        scanf("%lld", &n);
        ll num = 0LL;
        vector<vector<ll>> ans;
        vector<ll> alt;
        int maxx = 0;
        for(ll i = 2; i <= sqrt(n)+1 ; ++i){
            alt.clear();
            num = 0LL;
            ll k = n, tot = 1LL;
            while(k > 1 && k%i == 0 && ((((k/i)%i) == 0) || (k/i) == 1)){
                k/=i;
                alt.push_back(i); 
                tot*=i;
            }
            if(tot*k == n && k > 1) alt.push_back(k);
            else if(tot != n) alt.clear();
            if(!alt.empty()) {
                maxx = max(maxx, (int)alt.size());
                ans.push_back(alt);
            }
        }

        printf("%d\n", maxx);
        for(int i = 0; i < (int)ans.size() && maxx ; ++i){
            if((int)ans[i].size() == maxx){
                for(ll x : ans[i]) printf("%lld ", x);
                printf("\n");
                break;
            }
        }
    }
    return 0;
}