//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
//1337. The K Weakest Rows in a Matrix
class Solution {
public:
    
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b){
        if(a.second > b.second) return true;
        else if(a.second < b.second) return false;
        else return a.first < b.first;
    }
    
    int bs(vector<int> v, const int sz){
        int hi = sz - 1, lo = 0, mid;
        while(lo <= hi){
            mid = (lo+hi) >> 1;
            if(v[mid] > 0) lo++;
            else hi--;
        }
        return v[mid] < 1 ? sz - mid : 0;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& m, int k) {
        vector<int> ans;
        vector<pair<int,int> > a;
        for(int i = 0; i < m.size(); ++i) a.push_back(make_pair(i,bs(m[i], m[i].size())));

        sort(a.begin(), a.end(), cmp);
        
        for(int i = 0; i < k ; ++i) ans.push_back(a[i].first);
        return ans;
    }
    
};