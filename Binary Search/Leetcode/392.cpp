#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sz1 = s.size(), sz2 = t.size(), last = 0;
        bool found;
        for(int i = 0; i < sz1 ; ++i){
            int hi = sz2-1, lo = last+1, mid;
            found = false;
            while(lo<=hi){
                mid = (lo+hi)>>1;
                if(s[i] == t[mid]){
                    found = true;
                    last = mid;
                    break;
                }
            }
        }
    }
};

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    Solution a;
    cout << (a.isSubsequence(s1,s2) ? "true" : "false") << endl;
    return 0;
}