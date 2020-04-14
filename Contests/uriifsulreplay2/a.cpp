#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

ll solve2(ll num, ll& pot){
    if(num == 10) return 3LL;
    ll k = solve2(num/10LL, pot)-1;
    return k*10LL + 2*pow(10,pot++)+1;
}


ll solve(ll num){
    ll pot = 1LL;
    return solve2(num, pot);
}

ll calcRest(ll num){
    string ans;
    ll n7 = 0LL, n1 = 0LL;
    for(ll i = 1LL; i <= num ; ++i){
        ans=to_string(i);
        for(char c : ans){
            if(c == '1') n1++;
            if(c == '7') n7++;
        }
    }
    return n1+n7;
}

ll calc(ll num){
    if(num < 100) return calcRest(num);
    ll mod = 1000000000000;
    while(mod>num) mod/=10LL;
    ll ans = 0LL;
    while(1){
       if(num - mod > mod){
            ll md = num/mod;
            if(md > 7) ans+= md*solve(mod)+mod*2- md;
            else if(md == 7) ans+= md*solve(mod)+mod*2- md - (mod-num%mod-1);
            else if(md > 1) ans+= md*solve(mod)+mod-md;
            return ans + calc(num%mod); 
        }
        num -= mod;
        ans+=solve(mod)+num;
        if(num < 100) return ans+calcRest(num);
        while(mod > num) mod/=10LL;
    }
    return ans;
}

int main(){
    ll a;
    scanf("%lld", &a);
    printf("%lld\n", calc(a));
    return 0;
}