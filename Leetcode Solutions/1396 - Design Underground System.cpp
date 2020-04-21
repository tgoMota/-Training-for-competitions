//https://leetcode.com/contest/weekly-contest-182/problems/design-underground-system/
//1396. Design Underground System
class UndergroundSystem {
public:
    map<string,vector<pair<int,int>>> mpin;
    map<string,vector<pair<int,int>>> mpout;
    UndergroundSystem() {
        mpin.clear();
        mpout.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        mpin[stationName].push_back({id,t});
    }
    
    void checkOut(int id, string stationName, int t) {
        mpout[stationName].push_back({id,t});
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<pair<int,int>>&a = mpin[startStation];
        vector<pair<int,int>>&b = mpout[endStation];
        int sum = 0;
        unordered_map<int,int> ans;
        for(auto x : a){
            ans[x.first] = x.second;
        }
        int cnt = 0;
        for(auto x : b){
            if(ans.find(x.first) != ans.end()) {
                sum+= x.second - ans[x.first];
                cnt++;
            }
        }
        return sum/(double)cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */