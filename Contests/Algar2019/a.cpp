#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    string a;
    scanf("%d", &n);
    while(n--){
        cin >> d;
        cin.ignore();
        getline(cin, a);
        int sz = a.size();
        if(d > sz){
            int k = d/sz;
            d -= (k*sz);
        }
        if(d < sz){
            string sb = a.substr(0,d);
            a.erase(0,d);
            a+=sb;
        }
        printf("%s\n", a.c_str());
    }

    return 0;
}