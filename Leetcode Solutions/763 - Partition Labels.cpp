//https://leetcode.com/problems/partition-labels/
//763. Partition Labels
class Solution {
public:
    unordered_map<int,pair<int,int>> cnt;
    vector<int> partitionLabels(string s) {
        for(int i = 0; i < s.size() ; ++i){
            cnt[s[i]-'a'].first++; //count of occurences
            cnt[s[i]-'a'].second = i; //last occurence
        }
        vector<int> ans;
        for(int i = 0; i < s.size() ; ++i){
            auto k = cnt[s[i]-'a'];
            int best = k.second;
            for(int j = i+1; j < best+1 ; ++j){
                auto nk = cnt[s[j]-'a'];
                best = max(best, nk.second);
            }
            ans.push_back(best-i+1);
            i = best;
        }
        return ans;
    }
};