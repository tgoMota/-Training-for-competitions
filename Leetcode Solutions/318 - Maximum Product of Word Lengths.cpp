//https://leetcode.com/problems/maximum-product-of-word-lengths/
//318. Maximum Product of Word Lengths
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int N = words.size();
        vector<int> masks(N, 0);
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < words[i].size() ; ++j){
                int k = words[i][j] - 'a';
                masks[i] |= 1<<k;
            }
        }
        int mx = 0;
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < N ; ++j){
                if(i == j || (masks[i] & masks[j]) != 0) continue;
                int lh = words[i].size() * words[j].size();
                mx = max(mx, lh);
            }
        }
        return mx;
    }
};