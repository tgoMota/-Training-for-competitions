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

ll calc(ll A, ll B, ll x){
    //printf("calc = %lld\n", floor((A*x)/(double)B) - A*floor(x/(double)B));
    return floor((A*x)/(double)B) - A*floor(x/(double)B);
}

int main(){
    ll A, B, N;
    scanf("%lld%lld%lld", &A, &B, &N);

    ll ans = 0;

    if(A <= N) ans = max(ans, calc(A,B,A));
    if(B <= N) ans = max(ans, calc(A, B, B));
    ans = max(ans, calc(A,B,N));
    printf("%lld\n", ans);
    return 0;
}