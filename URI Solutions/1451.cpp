//https://www.urionlinejudge.com.br/judge/pt/problems/view/1451
//URI 1451 - Teclado Quebrado
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
const int mod = 1e9+7;
typedef long long ll;
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
int main() {
  list<char> answer;
  string s;
       
  while (cin >> s) {
   	answer.clear();
   	auto it = answer.begin();
      	
   	for (char c : s) {
   		if (c == ']') it = answer.end();
      else if (c == '[') it = answer.begin();
   		else answer.insert(it, c);
   	}
        	
   	for (auto it = answer.begin(); it != answer.end(); it++) {
   		printf("%c", *it);
   	}
        	
   	printf("\n");
  }
        
  return 0;
}