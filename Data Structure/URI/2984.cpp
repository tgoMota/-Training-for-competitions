//https://www.urionlinejudge.com.br/judge/pt/problems/view/2984
//URI 2984 - Assuntos Pendentes
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.size() ; ++i){
        if(s[i] == '(') st.push('(');
        else if(!st.empty() && s[i] == ')') st.pop();
    }
    if(st.empty()) printf("Partiu RU!\n");
    else printf("Ainda temos %d assunto(s) pendente(s)!\n", st.size());

    return 0;
}