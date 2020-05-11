#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
 
int main(){
    int n;
    scanf("%d", &n);
    map<ll,int> m;
    vector<ll> B(n+1);
    ll ans = 0LL;
    for(int i = 1; i <= n ; ++i){
        int k;
        scanf("%d", &k);
        m[k+i]++;
        B[i] = i-k;
    }

    for(int i = 1; i <= n ; ++i){
        ans+= m[B[i]];
    }

    printf("%lld\n", ans);

    return 0;
}