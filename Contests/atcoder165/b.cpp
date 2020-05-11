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

double calc(ll mid, ll x){
    double c = pow(1.01, mid)*100;
    return pow(1.01, mid)*100LL >= x;
}

int main(){
    ll x;
    scanf("%lld", &x);
    ll y = 100LL;
    int t = 0;

    while(y < x){
        y=1.01*y;
        t++;
    }

    printf("%d\n", t);
    return 0;
}