//https://www.urionlinejudge.com.br/judge/pt/problems/view/3262
//URI 3262 - Timebomb
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//CHECK THE CONSTRAINTS, PLEASE
string check(vector<string>& v){
  if(v[0] == "***" && v[1] == "* *" && v[2] == "* *" && v[3] == "* *" && v[4] == "***") return "0"; //0
  if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[3] == v[4] && v[4] == "  *") return "1"; //1
  if(v[0] == "***" && v[1] == "  *" && v[2] == "***" && v[3] == "*  " && v[4] == "***") return "2"; //2
  if(v[0] == "***" && v[1] == "  *" && v[2] == "***" && v[3] == "  *" && v[4] == "***") return "3"; //3
  if(v[0] == "* *" && v[1] == "* *" && v[2] == "***" && v[3] == "  *" && v[4] == "  *") return "4"; //4
  if(v[0] == "***" && v[1] == "*  " && v[2] == "***" && v[3] == "  *" && v[4] == "***") return "5";//5
  if(v[0] == "***" && v[1] == "*  " && v[2] == "***" && v[3] == "* *" && v[4] == "***") return "6"; //6
  if(v[0] == "***" && v[1] == v[2] && v[2] == v[3] && v[3] == v[4] && v[4] == "  *") return "7"; //7
  if(v[0] == "***" && v[1] == "* *" && v[2] == "***" && v[3] == "* *" && v[4] == "***") return "8"; //8
  if(v[0] == "***" && v[1] == "* *" && v[2] == "***" && v[3] == "  *" && v[4] == "***") return "9"; //9
  return "";
}
vector<vector<string>> m;
void toToken(int idx, string& line){
    const int N = (int)line.size();
    for(int i = 0, j = 0; i < N ; i+=4, j++){
      string token = "";
      token += line[i];
      token += line[i+1];
      token += line[i+2];
      if(idx == 0) m.push_back(vector<string>());
      m[j].push_back(token);
    }
}
int main(){
    fastio();
    vector<string> v;
    string line = "";

    const int C = 5;
    for(int i = 0; i < 5 ; ++i){
      string line;
      getline(cin, line);
      toToken(i, line);
    }

    string num_str = "";
    for(vector<string>& digit : m){
      string tmp = check(digit);
      if(tmp.empty()){
        cout << "BOOM!!\n";
        return 0;
      }
      num_str += check(digit);
    }
    
    int num = stoi(num_str);
    if(num % 6 == 0) cout << "BEER!!\n";
    else cout << "BOOM!!\n";

    return 0;
}

