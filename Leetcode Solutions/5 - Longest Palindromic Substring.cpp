class Solution {
public:
    bool isPalindrome(string& b){
        string a = b;
        reverse(a.begin(), a.end());
        return a == b;
    }
    vector<int> LPS(string& pat){
        const int N = pat.size();
        vector<int> lps(N+1);
        int i = 0, j = -1;
        lps[0] = -1;
        while(i < N){
            while(j >= 0 && pat[i] != pat[j]) j = lps[j];
            i++, j++;
            lps[i] = j;
        }
        return lps;
    }
    
    int kmp(string& data, string& pat){
        const int N = data.size(), M = pat.size();
        vector<int> lps = LPS(pat);
        int i = 0, j = 0, ans = 0;
        while(i < N){
            while(j >= 0 && data[i] != pat[j]) j = lps[j];
            i++, j++;
            ans = max(ans, j);
        }
        return ans;
    }
    
    string longestPalindrome(string s) {
        const int N = s.size();
        string b = s;
        int mxsize = 0;
        string ans1 = "";
        reverse(b.begin(), b.end());
        while((int)b.size()){
            int ans = kmp(s, b);
            string temp = b.substr(0, ans);
            if(ans > mxsize && isPalindrome(temp)){
                ans1 = temp;
                mxsize = ans;
                //printf("mxsize = %d = ans1 = %s\n", mxsize, ans1.c_str());
            }
            if((int)ans1.size()>=(int)b.size()) break;
            b.erase(b.begin());
        }
        return ans1;
    }
    
    //"aacdefcaa"
    //"aacdefcaa"
};