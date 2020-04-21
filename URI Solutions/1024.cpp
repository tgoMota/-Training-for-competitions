#include <bits/stdc++.h>
using namespace std;
int n;
string frase;
int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin,frase);
        for(int i = 0; i < frase.size() ; ++i)
            if(isalpha(frase[i])) frase[i] += 3;
        reverse(frase.begin(), frase.end());
        for(int i = frase.size()/2; i < frase.size() ; ++i) frase[i] -= 1;
        cout << frase << endl;
    }

    return 0;
}