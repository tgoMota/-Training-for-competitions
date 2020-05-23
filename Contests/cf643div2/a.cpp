#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        ll a, k;
        scanf("%lld%lld", &a, &k);
        int mx = 0, minx = 9;
        ll cp = a;
        while(--k > 0){
            mx = 0, minx = 9;
            while(cp > 0){
                int r = cp % 10LL;
                mx = max(mx, r);
                minx = min(minx, r);
                cp/=10LL;
            }
            cp = a + mx*minx;
            if(!minx) break;
            a = cp;
        }
        printf("%lld\n", cp);
    }
    return 0;
}