#include <bits/stdc++.h>
using namespace std;

stack<char> pil;
int main(){
    int n, cont;
    cin >> n;
    string s;
    while(n--){
        while(!pil.empty()) pil.pop();
        cin >> s;
        cont = 0;
        for(int i = 0; i < s.size() ; ++i){
            if(s[i] == '<') pil.push(s[i]);
            if(s[i] == '>'){
                if(!pil.empty() && pil.top() == '<'){
                    cont++;
                    pil.pop();
                }
            }
        }
        cout << cont << endl;
    }

    return 0;
}

