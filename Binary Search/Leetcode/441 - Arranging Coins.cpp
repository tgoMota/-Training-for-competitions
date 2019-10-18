//https://leetcode.com/problems/arranging-coins/
//441. Arranging Coins
class Solution {
public:
    int arrangeCoins(int n) {
        int row = 1;
        while(n>0){
            n -= row;
            row++;
        }
        if(n == 0) return --row;
        else return row-=2;
    }
};