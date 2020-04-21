class Solution {
public:
    vector<int> LPS(vector<int>& pat){
        const int N = pat.size();
        vector<int> lps(N+1);
        int i = 0, j = -1;
        lps[0] = -1;
        while(i < N){
            while(j>=0 && pat[i] != pat[j]) j = lps[j];
            i++, j++;
            lps[i] = j;
        }
        return lps;
    }
    
    int kmp(vector<int>& data, vector<int>& pat){
        const int N = data.size(), M = pat.size();
        vector<int> lps = LPS(pat);
        int i = 0, j = 0, ans = 0;
        while(i < N){
            while(j >=0 && data[i] != pat[j]) j = lps[j];
            i++, j++;
            ans = max(ans, j);
            if(j == M) return M;
        }
        return ans;
    }
    
    int findLength(vector<int>& A, vector<int>& B) {
        int ans = 0;
        while((int)B.size()){
            ans = max(ans,kmp(A,B));
            if(ans == B.size()) return ans;
            B.erase(B.begin());
        }
        return ans;
    }
};