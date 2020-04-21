//https://leetcode.com/problems/reduce-array-size-to-the-half/
//1338. Reduce Array Size to The Half
class Solution {
public:
    unordered_map<int,int> m;
    int minSetSize(vector<int>& arr) {
        const int N = arr.size();
        set<pair<int,int>, greater<pair<int,int>>> st;
        
        for(int x : arr) m[x]++;
        
        for(auto& x : m) st.insert({x.second, x.first});
        
        int tot = N;
        auto it = st.begin();
        int ans = 0;
        for(auto x : st){
            m[x.second] = 0;
            tot -= (*it).first;
            ans++, it++;
            if(tot <= N/2) break;
        }
        
        return ans;
    }
};