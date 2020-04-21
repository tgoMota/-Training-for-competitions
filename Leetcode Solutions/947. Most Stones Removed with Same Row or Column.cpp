//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
//947. Most Stones Removed with Same Row or Column
class Solution {
vector<int> id;
int find(int x){
    if(id[x] != x) return find(id[x]);
    return x;
}
    
void unionS(int a, int b){
     int x = find(a), y = find(b);
     if(x != y) id[y] = x;
}
public:
    int removeStones(vector<vector<int>>& a) {
        int N = a.size();
        for(int i = 0; i < N ; ++i) id.push_back(i);
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < N ; ++j){
                if(i == j) continue;
                if(a[i][0] == a[j][0] || a[i][1] == a[j][1])
                    unionS(i, j);
            }
        }
        int ans = 0;
        for(int i = 0; i < N ; ++i)
            if(find(i) == i) ans++;
        return N-ans;
    }
    
};