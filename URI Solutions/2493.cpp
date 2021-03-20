//https://www.urionlinejudge.com.br/judge/pt/problems/view/2493
//URI 2493 - Jogo do Operador
#include <bits/stdc++.h>
using namespace std;
//CHECK THE CONSTRAINTS, PLEASE
struct ex{
  int a, b, c;
  string ans;
  ex(int _a, int _b, int _c){
    a = _a;
    b = _b;
    c = _c;
    if(a+b == c) ans = "+";
    else if(a-b == c) ans = "-";
    else if(a*b == c) ans = "*";
    else ans = "I";
  }
};
int n;
int main(){
    while(cin >> n){
      vector<ex> v;
      vector<string> ans;
      for(int i = 0; i < n ; ++i){
        int a, b, c;
        scanf("%d %d=%d", &a, &b, &c);
        v.push_back(ex(a,b,c));
      }

      for(int i = 0; i < n ; ++i){
        string a, c;
        int b;
        cin >> a;
        cin >> b;
        cin >> c;
        if(v[--b].ans != c) ans.push_back(a);
      }

      const int N = (int)ans.size();
      sort(ans.begin(), ans.end());
      if(ans.empty()){
        printf("You Shall All Pass!\n");
      }else if((int)ans.size() == n){
        printf("None Shall Pass!\n");
      }
      else{
        for(int i = 0; i < N ; ++i){
          if(i) printf(" ");
          printf("%s", ans[i].c_str());
        }
        printf("\n");
      }
    }
    return 0;
}
