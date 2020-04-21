//https://leetcode.com/contest/weekly-contest-182/problems/find-lucky-integer-in-an-array/
//1394. Find Lucky Integer in an Array
class Solution {
public:
    int v[501];
    int findLucky(vector<int>& arr) {
        for(int x : arr) v[x]++;
        int mx = -1;
        for(int i = 1; i <= 500 ; ++i) if(v[i] != 0 && v[i] == i) mx = max(mx, i);
        return mx;
    }
};