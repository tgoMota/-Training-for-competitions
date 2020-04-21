//https://leetcode.com/problems/reverse-string/
//344. Reverse String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        for(int i = 0; i < sz/2 ; ++i) swap(s[i], s[sz-i-1]);
    }
};