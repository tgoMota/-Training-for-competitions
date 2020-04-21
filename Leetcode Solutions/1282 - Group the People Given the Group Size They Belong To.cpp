//https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
//1282. Group the People Given the Group Size They Belong To
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groups) {
        vector<pair<int,int>> g;
        for(int i = 0; i < groups.size() ; ++i) g.push_back({groups[i], i});
        sort(g.begin(), g.end(), [&](pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        });
        vector<vector<int>> ans;
        int k = 0;
        vector<int> nw;
        int lastsize = g[0].first;
        for(int i = 0; i < g.size() ; ++i){
            nw.push_back(g[i].second);
            if(nw.size() == g[i].first){
                ans.push_back(nw);
                nw.clear();
            }
        }
        return ans;
    }
};