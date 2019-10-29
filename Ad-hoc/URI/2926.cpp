//https://www.urionlinejudge.com.br/judge/pt/problems/view/2926
//URI 2926 - Então é Natal!
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a = "Entao eh Natal!";
    string b = "";
    for(int i = 0; i < a.size() ; ++i){
        if(a[i] != 'a') b+=a[i];
        else for(int j = 0; j < n ; ++j) b+='a';
    }
    cout << b << endl;
    return 0;
}