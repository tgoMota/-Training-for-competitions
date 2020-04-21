#define max3(a,b,c) max(a,max(b,c))
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> v;
        v.push_back(make_pair(a, 'a'));
        v.push_back(make_pair(b, 'b'));
        v.push_back(make_pair(c, 'c'));
        sort(v.begin(), v.end(), [&](pair<int,char> &a, pair<int,char>& b){
           return a.first > b.first; 
        });
        string ans = "";
        int index = 0;
        while(v[0].first > 0){
            int pos = 0;
            char ch = v[pos].second;
            int qtd = v[pos].first;
            bool justOne = false;
            if(index > 0 && ans.back() == v[0].second){
                pos = 1;
                ch = v[pos].second;
                qtd = v[pos].first;
                justOne = true;
                if(qtd == 0) break;
            }
            index++;
            for(int i = 0; i < 2-justOne && v[pos].first>0 ; i++, v[pos].first--) ans+=v[pos].second;
            //sort
            sort(v.begin(), v.end(), [&](pair<int,char> &a, pair<int,char>& b){
               return a.first > b.first; 
            });
        }
        return ans;
    }
};