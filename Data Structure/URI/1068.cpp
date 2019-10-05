#include <bits/stdc++.h>
using namespace std;
string line;
stack<char> pil;
bool yes;
int main(){
    while(getline(cin,line)){
        while(!pil.empty()) pil.pop();
        yes = true;
        for(int i = 0; i < line.size() ; ++i){
            if(line[i] == '(') pil.push(line[i]);
            if(line[i] == ')'){
                if(!pil.empty() && pil.top() == '('){
                    pil.pop();
                }else{
                    yes = false;
                    break;
                }
            }
        }
        if(pil.empty() && yes) cout << "correct\n";
        else cout << "incorrect\n";
    }
    return 0;
}