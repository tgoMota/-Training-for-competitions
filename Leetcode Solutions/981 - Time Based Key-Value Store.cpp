class TimeMap {
public:
    /** Initialize your data structure here. */
    map<pair<string,int>, string> m;
    unordered_map<string,set<int,greater<int>>> m1;
    TimeMap() {
        m.clear();
        m1.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[{key,timestamp}] = value;
        m1[key].insert(timestamp);
    }
    
    string get(string key, int timestamp) {
        auto it = m1[key].lower_bound(timestamp);
        if(*it > timestamp) return "";
        return m[{key, *it}];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */