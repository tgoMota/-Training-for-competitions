#include <bits/stdc++.h>
using namespace std;

multiset<int> par;
multiset<int,greater<int>> impar;

int main(){
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x % 2) impar.insert(x);
        else par.insert(x);
    }
    while(!par.empty()){
        cout << *par.begin() << endl;
        par.erase(par.begin());
    }
    while(!impar.empty()){
        cout << *impar.begin() << endl;
        impar.erase(impar.begin());
    }

    return 0;
}
