#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef long long ll;
const int M = 11234;
ll dp[M][2];

int main(){
    int N;
    vector<int> data;
    while(scanf("%d", &N) != EOF){
        data.assign(N,0);
        for(int& x : data) scanf("%d", &x);
        for(int i = 0 ; i < N-1 ; ++i) dp[i][0] = max(data[i], data[i+1]);
        
        int turn = 0, pastTurn;
        for(int interval = 4; interval <= N ; interval+=2){
            pastTurn = turn;
            turn = 1-turn;
            for(int i = 0, j = interval-1 ; j < N ; ++i, ++j){
                ll left = data[i] + min(dp[i+1][pastTurn], dp[i+2][pastTurn]);
                ll right = data[j] + min(dp[i][pastTurn], dp[i+1][pastTurn]);
                dp[i][turn] = max(left, right);
            }
        }

        printf("%lld\n", dp[0][turn]);
    }
    return 0;
}