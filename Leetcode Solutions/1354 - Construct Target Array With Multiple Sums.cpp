//https://leetcode.com/problems/construct-target-array-with-multiple-sums/
//1354. Construct Target Array With Multiple Sums
class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int>& target) {
        const int N = target.size();
        priority_queue<int> q;
        long long sum = 0LL;
        for(int x : target){
            sum+=x;
            q.push(x);
        }
        while(sum > 1LL && q.top() > sum-q.top()){
            int t = q.top();
            q.pop();
            sum -= t;
            if(sum<=1) return sum;
            q.push(t%sum);
            sum+=t%sum;
        }
        return sum == q.size();
    }
};