//https://www.urionlinejudge.com.br/judge/pt/problems/view/1279
//URI 1279 - Ano Bissexto ou Ano não Bissexto
#include <bits/stdc++.h>
using namespace std;

bool divisibleBy3(const string& a){
    int sum = 0, sz = a.size();
    for(int i = 0; i < sz ; ++i) sum+= (a[i]-'0');
    return sum%3 == 0;
}
bool divisibleBy4(const string& a){
    int sz = a.size(), num = (a[sz-1] - '0') + ((a[sz-2]-'0')*10);
    return num % 4 == 0;
}
bool divisibleBy5(const string& a){
    return (a.back() == '0' || a.back() == '5');
}

bool divisibleBy11(const string& a){
    int odd = 0, even = 0, sz = a.size();
    for(int i = 0; i < sz ; ++i){
        if(i%2 == 0) even += (a[i]-'0');
        else odd += (a[i]-'0');
    }
    return (odd-even)%11 == 0;
}
bool divisibleBy100(const string& a){
    int sz = a.size();
    if(sz >= 3 && a[sz-1] == '0' && a[sz-2] == '0') return true;
    else return false;
}

bool divisibleBy400(const string& a){
    int sz = a.size();
    int c = (a[sz-3] - '0');
    int d = (a[sz-4] - '0')*10;
    return (c+d)%4 == 0 && divisibleBy100(a);
}

int main(){
    string s;
    int t = 0, l;
    while(cin >> s){
        if(t++) printf("\n");
        l = 0;
        if(divisibleBy4(s) && (!divisibleBy100(s) || divisibleBy400(s))) {
            printf("This is leap year.\n");
            l+=5;
        }
        if(divisibleBy3(s) && divisibleBy5(s)){
            printf("This is huluculu festival year.\n");
            ++l;
        }
        if(l>4 && divisibleBy5(s) && divisibleBy11(s)) printf("This is bulukulu festival year.\n");

        if(l == 0) printf("This is an ordinary year.\n");

        // printf("Divisivel por 3  : %d\n", divisibleBy3(s));
        // printf("Divisivel por 4  : %d\n", divisibleBy4(s));
        // printf("Divisivel por 5  : %d\n", divisibleBy5(s));
        // printf("Divisivel por 11 : %d\n", divisibleBy11(s));
        // printf("Divisivel por 100: %d\n", divisibleBy100(s));
        // printf("Divisivel por 400: %d\n", divisibleBy400(s));
    }

    return 0;
}