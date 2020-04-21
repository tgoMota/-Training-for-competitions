//https://leetcode.com/problems/heaters/
//475. Heaters
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int lastHeater = heaters.back(), lastHouse = houses.back(), mx = 0;
        
        for(int i = 0; i < houses.size() ; ++i){
            if(houses[i] < heaters[0]) mx = max(mx,heaters[0]-houses[i]);
            else if(houses[i] > lastHeater) mx = max(mx,houses[i]-lastHeater);
            else{
                int idx = upper_bound(heaters.begin(), heaters.end(), houses[i])-heaters.begin();
                if(idx < heaters.size()) mx = max(mx,min(heaters[idx]-houses[i], houses[i]-heaters[idx-1]));
            }
        }
        return mx;
    }
};
