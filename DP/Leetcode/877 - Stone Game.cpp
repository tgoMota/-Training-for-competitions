//https://leetcode.com/problems/stone-game/
//877. Stone Game
class Solution {
public:
    int memo[1005][1005];
    const int oo = 0x3f3f3f3f;
    bool stoneGame(vector<int>& piles) {
        memset(memo, -1,sizeof(memo));
        return (dp(0,0,piles.size()-1, piles) > 0);
    }
    int dp(int turn, int i, int j, vector<int>& piles){
        if(j < 0 || i >= piles.size()) return 0;
        if(j <= i) return turn == 0? piles[i] : -piles[i];
        int& ans = memo[i][j];
        if(ans != -1) return ans;
        if(turn == 1) 
            return ans = min(dp(turn=(turn+1)%2,i+1,j,piles)-piles[i], dp(turn=(turn+1)%2,i,j-1,piles)-piles[j]);
        else
            return ans = max(dp(turn=(turn+1)%2,i+1,j,piles)+piles[i], dp(turn=(turn+1)%2,i,j-1,piles)+piles[j]);
    }
};