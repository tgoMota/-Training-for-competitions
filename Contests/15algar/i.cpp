#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  vector<vector<string>> v;
  vector<string> p = {"excelente", "bom", "otimo", "adoro", "amo"};
  vector<string> r = {"ruim", "pessimo", "odeio", "droga", "fraco"};
  string neg = "nao";
  while(scanf("%d", &n) != EOF){
    v.clear();
    v.resize(n);
    string line;
    cin.ignore();
    while(n--){
      getline(cin, line);
      string s = "";
      const int N = line.size();
      for(int i = 0; i < N ; ++i){
        if(line[i] != ' ') {
          if(isalpha(line[i])) s+= line[i];
          if(i == N-1) v[n].push_back(s);
        }
        else if(line[i] == ' ') {
          v[n].push_back(s);
          s =  "";
        }
      }
    }

    int pn = 0, ans = 0;
    bool isNeg = false;
    for(int i = 0; i < v.size() ; ++i){
      pn = 0;
      for(string& x : v[i]){
        if(x == neg){
          isNeg = true;
          continue;
        }
        for(string& y : p){
          if(x == y) pn += !isNeg;
        }
        for(string& y : r){
          if(x == y) pn += isNeg;
        }
        isNeg = false;
      }
      if(pn > 0) ans++;
      else if(pn < 0) ans--;
    }

    if(ans > 0) printf("positivo\n");
    else if(ans < 0) printf("negativo\n");
    else printf("neutro\n");
  }
  return 0;
}