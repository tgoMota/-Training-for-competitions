class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int x : arr) m[x] = 1;
        int ans = 0;
        for(int x : arr) if(m.find(x+1) != m.end()) ans++;
        return ans;
    }
};