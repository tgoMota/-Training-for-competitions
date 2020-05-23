//https://codeforces.com/contest/834/problem/D
//D. The Bakery
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
vector<int> cakes;
vector<int> freq;
vector<vector<int>> memo;

int L = 1, R, mid;

int cost(int l, int r){
    while(L < l){
        --freq[cakes[L]];
        if(freq[cakes[L]] == 0) mid--;
        L++;
    }

    while(l < L){
        --L;
        if(freq[cakes[L]] == 0) mid++;
        freq[cakes[L]]++;
    }

    while(R > r){
        freq[cakes[R]]--;
        if(freq[cakes[R]] == 0) mid--;
        R--;
    }

    while(r > R){
        R++;
        if(freq[cakes[R]] == 0) mid++;
        freq[cakes[R]]++;
    }

     return mid;
}

void solve(int box, int la, int lb, int ba, int bb){
    if(la > lb) return ;

    int md = (la + lb) >> 1;
    int bestlimit = -1;
    int minlimitb = min(bb, md);
    int prev = !(box&1);
    for(int i = ba ; i <= minlimitb ; ++i){
        int new_value = memo[i-1][prev]+cost(i,md);
        if(new_value >= memo[md][box&1]){
            memo[md][box&1] = new_value;
            bestlimit = i;
        }
    }

    solve(box, la, md-1, ba, bestlimit);
    solve(box, md+1, lb, bestlimit, bb);
}


int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    cakes.resize(n+1);
    freq.resize(n+1);
    memo.assign(n+1, vector<int>(2, 0));
    for(int i = 1; i <= n ; ++i) {
        scanf("%d", &cakes[i]);
    }

    for(int i = 1; i <= n ; ++i){
        memo[i][1] = cost(1,i);
    }

    for(int i = 2; i <= k ; ++i){
        solve(i,1,n,1,n);
    }

    printf("%d\n", memo[n][k&1]);

    return 0;
}