//https://codeforces.com/problemset/problem/706/C
//Wrong answer on test 9 !!!!!!!!
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f3f3f3f3f 
typedef long long ll;
const int m = 1e5+7;
int en[m], n;
ll memo[4][m];
string v[m];

ll dp(int ind,int goswap, string ant){ // goswap = swaped = ( 0 => NO , 1 => swap 1&n , 2 => swap 2&n-1, 3 => swap both )
    if(ind > n) return 0;
    if(goswap && v[ind].size() == 1 || goswap >= 2 && v[ind].size() <= 3) return oo;
    string newStr = v[ind];
    ll energy = 0LL;
    if(goswap){
        energy += en[ind];
        int len = newStr.size();
        if(goswap == 1 || goswap == 3) swap(newStr[0], newStr[len-1]);
        if(goswap == 2 || goswap == 3) swap(newStr[1], newStr[len-2]);
    }
    if(newStr < ant) return oo;
    ll& ans = memo[goswap][ind];
    if(ans != -1) return ans;
    ans = oo;
    for(int i = 0; i <= 3 ; ++i) ans = min(ans,dp(ind+1,i,newStr)+energy);
    return ans;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n ; ++i) cin >> en[i];
    for(int i = 1; i <= n ; ++i) cin >> v[i];
    memset(memo, -1, sizeof(memo));
    ll ans = oo;
    for(int i = 0; i <= 3 ; ++i) ans = min(ans,dp(1,i,""));
    cout << (ans < oo ? ans : -1) << endl;
    return 0;
}