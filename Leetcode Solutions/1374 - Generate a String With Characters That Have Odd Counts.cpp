//https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
//1374. Generate a String With Characters That Have Odd Counts
class Solution {
public:
    string generateTheString(int n) {
        string a = "";
        for(int i = 0; i < n-1 ; ++i){
            a+='a';
        }
        if(n % 2 == 0) a+='b';
        else a+='a';
        return a;
    }
};