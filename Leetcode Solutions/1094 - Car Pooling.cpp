//https://leetcode.com/problems/car-pooling/
//1094. Car Pooling
class Solution {
public:
    bool carPooling(vector<vector<int>>& tr, int cap) {
        sort(tr.begin(), tr.end(), [&](vector<int>& a, vector<int>& b){
           return a[1] < b[1]; 
        });
        multiset<pair<int,int>> s; //<timeend,sum>
        int sum = 0;
        for(int i = 0; i < tr.size() ; ++i){
            int timebegin = tr[i][1];
            while(s.begin() != s.end() && (*s.begin()).first <= timebegin){
                sum-= (*s.begin()).second;
                s.erase(s.begin());
            }
            sum+= tr[i][0];
            if(sum > cap) return false;
            s.insert(make_pair(tr[i][2], tr[i][0]));
        }
        return true;
    }
};