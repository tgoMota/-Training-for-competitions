//https://leetcode.com/problems/rank-teams-by-votes/
//1366. Rank Teams by Votes
class Solution {
public:
    static bool cmp(pair<char,vector<int>>&a, pair<char,vector<int>>&b){
        for(int i = 0; i < a.second.size() ; ++i){
            if(a.second[i] < b.second[i]) return false;
            else if(a.second[i] > b.second[i]) return true;
        }
        return a.first < b.first;
    }
    
    string rankTeams(vector<string>& v) {
        vector<bool> used(26,false);
        vector<pair<char,vector<int>>> arr;
        int mx = 0;
        for(int i = 0; i < v[0].size() ; ++i) {
            used[v[0][i]-'A'] = true;
            mx = max(mx,(int)(v[0][i]-'A'));
        }
        for(int i = 0; i <= mx ; ++i){
            if(!used[i]) continue;
            vector<int> a(v[0].size(),0);
            for(int j = 0; j < v.size() ; ++j){
                for(int k = 0; k < v[0].size() ; ++k){
                    if(v[j][k]-'A' == i){
                        a[k]++;
                        break;
                    }
                }
            }
            arr.push_back(make_pair(i+'A', a));
        }
        sort(arr.begin(), arr.end(), cmp);
        string ans = "";
        for(auto x : arr) ans+=x.first;
        return ans;
    }
};