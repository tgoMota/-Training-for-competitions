class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int, greater<int>> m;
        for(int x : stones) m.insert(x);
        while((int)m.size()>1){
            auto it1 = m.begin();
            auto it2 = m.begin();
            it2++;
            if(*it1 == *it2){
                m.erase(it2);
                m.erase(it1);
            }else {
                int newValue = *it1 - *it2;
                m.erase(it2);
                m.erase(it1);
                m.insert(newValue);
            }
        }
        if((int)m.size()) return *m.begin();
        else return 0;
    }
};