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
    int A, B, C, D;
    scanf("%d%d%d%d", &A, &B, &C, &D);
    vector<ll> pref(2*D+5, 0);
    for(int i = A; i <= B ; ++i){
        pref[i+B]++;
        pref[i+C+1]--;
    }

    for(int i = 1; i <= 2*D; ++i){
        pref[i] += pref[i-1];
    }

    for(int i = 2*D ; i > 0 ; i--){
        pref[i-1] += pref[i];
    }

    ll ans = 0LL;
    for(int i = C; i <= D ; ++i){
        ans += pref[i+1];
    }

    printf("%lld\n", ans);

    return 0;
}