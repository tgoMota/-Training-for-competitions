#include <bits/stdc++.h>
using namespace std;
stack<int> entrada, estac;
int n, a;
bool can(int resta){
    while(!entrada.empty()){
        a = entrada.top();
        entrada.pop();
        estac.push(a);
        while(!estac.empty() && estac.top() == resta){
            estac.pop();
            resta--;
        }
        if(estac.size() == resta) break;
    }

    return resta == 0;
}

int main(){
    while(cin >> n){
        if(n == 0) break;
        a = 1;
        while(a){
            while(!entrada.empty()) entrada.pop();
            while(!estac.empty()) estac.pop();
            for(int i = 1; i <= n ; ++i){
                cin >> a;
                if(!a) break;
                entrada.push(a);
            }
            if(!a) continue;
            string ans = can(n) ? "Yes\n" : "No\n";
            cout << ans;
        }
        cout << endl;
    }

    return 0;
}
