class Solution {
public:
    
    bool check(string& data, string& pat){
        int i, j;
        for(i = 0, j = 0; i < data.size() ; ++i){
            if(j != pat.size() && data[i] == pat[j]) j++;
            else if(data[i] < 'a' || data[i] > 'z') return false;
        }
        return j == (int)pat.size();
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string& x : queries) ans.push_back(check(x, pattern));
        return ans;
    }
};