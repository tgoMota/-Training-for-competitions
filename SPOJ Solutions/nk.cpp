#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f;
#define ooLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef pair<int,int> pii;
 
vector<int> wg;
vector<vector<ll>> memo;
 
int cost(int to, int from){
    return abs(to-from)*wg[from];
}
 
ll allcost(int to, int limit){
    ll sum = 0LL;
    for(int i = to+1; i <= limit ; ++i) sum+= cost(to,i);
    return sum;
}
 
void solve(int pile, int cordinatesA, int cordinatesB, int limitA, int limitB){
    if(cordinatesA > cordinatesB) return;
    int mid = (cordinatesA + cordinatesB) >> 1;
 
    memo[pile][mid] = ooLL;
    int newlimit = -1;
    for(int i = limitA; i <= limitB ; ++i){
        ll new_value = allcost(i+1,mid) + memo[pile-1][i];
        if(new_value <= memo[pile][mid]){
            memo[pile][mid] = new_value;
            newlimit = i;
        }
    }
 
    solve(pile, cordinatesA, mid-1, limitA, newlimit);
    solve(pile, mid+1, cordinatesB, newlimit, limitB);
}
 
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    wg.resize(n+1);
    for(int i = 1; i <= n ; ++i) scanf("%d", &wg[i]);
 
    memo.assign(k+1, vector<ll>(n+1));
    for(int leaves = 1; leaves <= n ; ++leaves) memo[1][leaves] = allcost(1,leaves);
 
    for(int pile = 2; pile <= k ; ++pile) solve(pile, 0, n, 0, n);
 
    printf("%lld\n", memo[k][n]);
 
    return 0;
}