//https://leetcode.com/problems/convert-a-number-to-hexadecimal/
//405. Convert a Number to Hexadecimal
class Solution {
public:
    char toHex2(int dec){
        if(dec <= 9) return dec+48;
        return (dec-10)+'a';
    }
    
    string toHex(int num) {
      if(num == 0) return "0";
      string ans;
      for(int i = 0; i < 32 && num ; i+=4){
          ans += toHex2(15 & num);
          num >>= 4;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};