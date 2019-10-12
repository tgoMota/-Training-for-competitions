#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int sz = s.size(),i;
        for(i = 0; i < sz ; i+=2*k){
            if(i+k>=sz) reverse(s.begin()+i, s.end());
            else reverse(s.begin()+i, s.begin()+i+k);
        }
        return s;
    }
};

int main(){
    int k;
    string s;
    cin >> k;
    Solution a;
    cin >> s;
    cout << a.reverseStr(s,k) << endl;
    return 0;
}