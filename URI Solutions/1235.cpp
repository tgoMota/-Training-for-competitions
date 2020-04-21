#include <bits/stdc++.h>
using namespace std;
int n;
string frase;

int main(){
    cin >> n;
    cin.ignore();
    while(n--){
        getline(cin,frase);
        reverse(frase.begin(), frase.begin() + frase.size()/2);
        reverse(frase.begin() + frase.size()/2, frase.end());
        cout << frase << endl;
    }

    return 0;
}