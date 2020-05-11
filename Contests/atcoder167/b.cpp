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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll sum = 0LL;
    if(a+b >= d) sum = min(a,d);
    else {
        sum += a, d-=(a+b);
        sum -= min(d, c);
    }

    printf("%lld\n", sum);
    return 0;
}