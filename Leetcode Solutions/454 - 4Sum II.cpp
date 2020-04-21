//https://leetcode.com/problems/4sum-ii/
//454. 4Sum II

//Solution O(N^2 * logN)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int> m;
        const int S = A.size();
        for(int i = 0; i < S ; ++i){
            for(int j = 0; j < S ; ++j){
                m[A[i] + B[j]]++;
            }
        }
        
        int count = 0;
        for(int i = 0; i < S ; ++i){
            for(int j = 0; j < S ; ++j){
                count += m[0 - C[i] - D[j]];
            }
        }
        return count;
    }
};

//Solution Brute Force O(N^4) - TLE
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0, S = A.size();
        for(int i = 0; i < S ; ++i){
            for(int j = 0; j < S ; ++j){
                for(int k = 0; k < S ; ++k){
                    for(int l = 0; l < S ; ++l){
                        if(A[i] + B[j] + C[k] + D[l] == 0) count++;
                    }
                }
            }
        }
        return count;
    }
};