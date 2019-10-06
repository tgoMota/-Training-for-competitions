//https://codeforces.com/problemset/problem/706/C
//"C. Hard problem"
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f3f3f3f3f
typedef long long ll;
const int m = 1e5+7;
int en[m], n;
ll memo[2][m];
string v[m];

ll dp(int ind,int goswap, string ant){ // goswap = swaped = ( 0 => NO reverse , 1 => reverse string )
    if(ind > n) return 0;
    if(goswap && v[ind].size() == 1) return oo;
    string newStr = v[ind];
    ll energy = 0LL;
    if(goswap){
        energy += en[ind];
        reverse(newStr.begin(), newStr.end());
    }
    if(newStr < ant) return oo;
    ll& ans = memo[goswap][ind];
    if(ans != -1) return ans;
    return ans = min(dp(ind+1,0,newStr)+energy, dp(ind+1, 1, newStr)+energy);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n ; ++i) cin >> en[i];
    for(int i = 1; i <= n ; ++i) cin >> v[i];
    memset(memo, -1, sizeof(memo));
    ll ans = min(dp(1,0,""),dp(1,1,""));
    cout << (ans < oo ? ans : -1) << endl;
    return 0;
}