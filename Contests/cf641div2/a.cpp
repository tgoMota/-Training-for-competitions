#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int least(int a){
    if(a % 2 == 0) return 2;
    for(int i = 3; i <= a/2+1; ++i) if(a % i == 0) return i;
    return a;
}
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, k;
        scanf("%d%d", &n, &k);
        ll ans = 0LL;
        if(n % 2 == 0) ans = n+2*k;
        else {
            ans = n + least(n) + 2*(k-1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}