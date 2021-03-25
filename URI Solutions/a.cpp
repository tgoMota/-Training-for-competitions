//https://www.urionlinejudge.com.br/judge/pt/problems/view/3065
//URI 3065 - Calculando
#include <bits/stdc++.h>
using namespace std;
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    int n, t = 1;
    while(cin >> n && n){
      string ex;
      cin >> ex;
      string ops = "";
      vector<int> nums;
      const int N = (int)ex.size();
      stack<char> st;
      int sum = 0;
      for(int i = 0; i < N ;){
        string num_str = "";
        while(i < N && isdigit(ex[i])) num_str += ex[i++];
        int num = stoi(num_str);
        if(st.empty()) sum += num;
        else{
          char op = st.top();
          st.pop();
          if(op == '+') sum += num;
          else sum -= num;
        }

        if(i < N) st.push(ex[i++]);
      }
      cout << "Teste " << t++ << '\n';
      cout << sum << "\n\n";
    }
    return 0;
}

