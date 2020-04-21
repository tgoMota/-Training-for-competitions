//https://www.urionlinejudge.com.br/judge/pt/problems/view/2569
//URI 2569 - A Bruxa do 7 x 1 
#include <bits/stdc++.h>
using namespace std;

void check(string& a){
    for(int i = 0; i < a.size() ; ++i)
        if(a[i] == '7') a[i] = '0';
}

int main(){
    string a, b, result = "";
    char op;
    cin >> a >> op >> b;
    check(a);
    check(b);

    long ai = strtol((char*)a.c_str(), nullptr, 10);
    long bi = strtol((char*)b.c_str(), nullptr, 10);
    long r = 0;

    if(op == '+') r = (ai+bi);
    else if(op == 'X' || op == 'x') r = (ai*bi);

    result = to_string(r);
    check(result);

    r = strtol((char*)result.c_str(), nullptr, 10);
    printf("%ld\n", r);

    return 0;
}