#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(cin >> s && !cin.eof()){
        stack<char> st;
        bool ok = true;
        for(char c: s){
            if(c == '(') st.push(c);
            else if(c == ')'){
                if(st.empty()){
                    ok = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()) ok = false;
        cout << (ok ? "correct\n" : "incorrect\n");
     }
    return 0;
}