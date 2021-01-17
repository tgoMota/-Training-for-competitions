//https://www.urionlinejudge.com.br/judge/pt/problems/view/1244
//URI 1244 - Ordenação por Tamanho
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    cin.ignore();
    for(int ti = 1; ti <= t ; ++ti){
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<pair<string,int>> v;
        string s;
        int idx = 0;
        while(getline(ss, s, ' ')){
          v.push_back({s, idx++});
        }

        sort(v.begin(), v.end(), [](pair<string,int> a, pair<string,int> b){
          if(a.first.length() == b.first.length()) return a.second < b.second;
          return a.first.length() > b.first.length();
        });

        for(int i = 0; i < (int)v.size() ; ++i){
          if(i) printf(" ");
          printf("%s", v[i].first.c_str());
        }
        printf("\n");
    }
    return 0;
}
