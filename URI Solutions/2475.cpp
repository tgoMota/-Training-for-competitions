//https://www.urionlinejudge.com.br/judge/pt/problems/view/2475
//URI 2475 - Confecção de Presentes
#include <bits/stdc++.h>
using namespace std;
#define ooLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
vector<vector<ll>> memo;
vector<int> gifts;
vector<ll> pref;

ll cost(int i, int j){
    if(i > j) return 0;
    return (pref[j]-pref[i-1]) * (j-i+1);
}

void solve(int helper, int giftA, int giftB, int limitA, int limitB){
    if(giftA > giftB) return ;

    int mid = (giftA+giftB) >> 1;

    memo[helper][mid] = ooLL;
    int newlimit = -1;
    for(int i = limitA; i <= limitB ; ++i){
        ll new_value = memo[helper-1][i] + cost(i+1,mid);
        if(new_value <= memo[helper][mid]){
            memo[helper][mid] = new_value;
            newlimit = i;
        }
    }

    solve(helper, giftA, mid-1, limitA, newlimit);
    solve(helper, mid+1, giftB, newlimit, limitB);
}


int main(){
    int P, A;
    scanf("%d%d", &P, &A);
    gifts.resize(P+1);
    pref.assign(P+1, 0);
    for(int i = 1; i <= P ; ++i) {
        scanf("%d", &gifts[i]);
        pref[i] += pref[i-1] + gifts[i];
    }
    memo.assign(A+1, vector<ll>(P+1));
    
    for(int i = 1; i <= P ; ++i){
        memo[1][i] = cost(1,i);
    }

    for(int i = 2; i <= A ; ++i) solve(i,0,P,0,P);
    printf("%lld\n", memo[A][P]);
    return 0;
}