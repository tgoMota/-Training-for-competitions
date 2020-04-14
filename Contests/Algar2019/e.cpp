#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string a;
    scanf("%d", &n);
    cin.ignore();
    getline(cin, a);
    for(int i = 0; i < n ; ++i) printf("%s\n", a.c_str());
    return 0;
}