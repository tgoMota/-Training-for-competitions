//https://www.hackerrank.com/contests/ioi-2014-practice-contest-2/challenges/guardians-lunatics-ioi14/problem
//[IOI] Guardians of the Lunatics 
//Learning Divide and Conquer Optimization
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

vector<ll> crazy;
vector<ll> pref;
vector<vector<ll>> memo;
vector<vector<int>> limit;

ll cost(int i, int j){
    return i > j ? 0 : (pref[j]-pref[i-1]) * (j-i+1);
}

void solve(int g, int la, int lb, int ga, int gb){
   // printf("\n\nsolve(%d,%d,%d,%d,%d)\n", g,la,lb,ga,gb);

    if(la > lb) return;

    int lm = (la+lb) >> 1;

    limit[g][lm] = -1;
    memo[g][lm] = ooLL;

    for(int i = ga; i <= gb ; ++i){
        ll new_value = memo[g-1][i] + cost(i+1, lm);
        if(new_value <= memo[g][lm]){
            //printf("em i = %d : new_value <= memo[%d][%d], new_value = %lld e memo = %lld\n", i,g, lm, new_value, memo[g][lm]);
            memo[g][lm] = new_value;
            limit[g][lm] = i;
        }
    }

    solve(g, la, lm-1, ga, limit[g][lm]);
    solve(g, lm+1, lb, limit[g][lm], gb);
}

int main(){
    int L, G;
    scanf("%d%d", &L, &G);
    crazy.resize(L+1);
    pref.assign(L+1,0);
    for(int i = 1; i <= L ; ++i) {
        scanf("%lld", &crazy[i]);
        pref[i]+=pref[i-1]+crazy[i];
    }

    memo.assign(G+1, vector<ll>(L+1));
    limit.assign(G+1, vector<int>(L+1));

    for(int i = 1; i <= L ; ++i){
        memo[1][i] = cost(1,i);
    }

    for(int i = 2; i <= G ; ++i) solve(i,0,L,0,L);

    printf("%lld\n", memo[G][L]);

    return 0;
}