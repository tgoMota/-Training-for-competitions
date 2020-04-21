class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> ans, ans2;
        for(int i = 1; i <= m ; ++i){
            ans.push_back(i);
        }
        
        for(int i = 0; i < q.size() ; ++i){
            int num = q[i];
            for(int j = 0; j < ans.size() ; ++j){
                if(ans[j] == num){
                    ans.erase(ans.begin()+j);
                    ans2.push_back(j);
                    break;
                }
            }
            ans.insert(ans.begin(), num);
            if((int)ans2.size() == (int)q.size()) break;
        }
        return ans2;
    }
};