//https://www.urionlinejudge.com.br/judge/pt/problems/view/2815
//URI 2815 - Digitador Gago
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    string line;
    getline(cin, line);
    istringstream ss(line);
    string ans = "", token;
    while(getline(ss, token, ' ')){
      const int sz = (int)token.size();
      if(!ans.empty()) ans += " ";
      ans += token.substr(0, sz < 2 ? 1 : 2);
      for(int i = 2; i < sz ; ++i){
        const int N = (int)ans.size();
        if(i < sz-1 && token.substr(i, 2) == ans.substr(N-2, 2)){
          i++;
          continue;
        }
        ans += token[i];
      }
    }
    cout << ans << '\n';


    return 0;
}

