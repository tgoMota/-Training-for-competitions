class Solution {
public:
    bool isSubstr(string& data, string& pat){
        if(data.size() < pat.size()) return false;
        for(int i = 0; i < data.size() ; ++i){
            if(data[i] == pat[0]){
                bool ok = true;
                int k, l;
                for(k = i, l = 0; k < data.size() && l < pat.size() ; ++k, ++l){
                    if(data[k] != pat[l]){
                        ok = false;
                        break;
                    }
                }
                if(ok && l == pat.size()) return true;
            }
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
         vector<string> ans;
         unordered_map<int,bool> vst;
         for(int i = 0; i < words.size() ; ++i){
             for(int j = 0; j < words.size(); ++j){
                if(i == j || vst[j]) continue;
                if(isSubstr(words[i], words[j])) {
                    ans.push_back(words[j]);
                    vst[j] = true;
                }
             }
         }
        return ans;
        
    }
};