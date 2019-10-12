//https://leetcode.com/problems/divisor-game/
//1025. Divisor Game
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int memo[2][1005];
    int dp(int ind, int N){
        if(N <= 1) return ind == 1; //ind 1 => alice wins
        int& ans = memo[ind][N];
        if(ans != -1) return ans;
        for(int i = N-1 ; i > 0 ; --i){
            if(N%i == 0 && (N-i)%2 == 1) return ans = dp((ind+1)%2, N-i);
        }
        return ans = dp((ind+1)%2, N-1);
    }
    bool divisorGame(int N) {
        memset(memo, -1, sizeof(memo));
        return dp(0, N);
    }
};
int main(){
    int n;
    cin >> n;
    Solution a;
    printf("%s\n", a.divisorGame(n)? "true" : "false");

    return 0;
}