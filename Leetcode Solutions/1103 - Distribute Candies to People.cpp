//https://leetcode.com/problems/distribute-candies-to-people/
//1103. Distribute Candies to People
class Solution {
public:
      
    vector<int> distributeCandies(int c, int N) {
        vector<int> ans(N, 0);
        int i = 0, sum = 0, j = 1;
        while(sum<c){
            if(sum+j <= c) ans[i]+=j;
            else ans[i]+= c-sum;
            sum+=j++;
            i = (i+1)%N;
        }
        return ans;
    }
};