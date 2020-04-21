class TweetCounts {
public:
    unordered_map<string, vector<int>> m;
    unordered_map<int, int> count;
    TweetCounts() {
        m.clear();
        count.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string name, int start, int end) {
        vector<int> v = m[name];
        int div;
        if(freq == "day") div = 86400;
        else if(freq == "hour") div = 3600;
        else div = 60;
        
        for(int x : v){
            if(x >= start && x<= end){
              //  printf("(%d-%d)/%d = %d\n", x,start ,div, (x-start)/div);
                count[(x-start)/div]++;
            }
        }
        vector<int> ans;
        int startTime = start/div, endTime = (end-start)/div;
        //printf("startTime = %d e endTime = %d\n", startTime, endTime);
        for(int i = 0; i <= endTime ; ++i) ans.push_back(count[i]);
        //printf("\n\n\n");
        count.clear();
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */