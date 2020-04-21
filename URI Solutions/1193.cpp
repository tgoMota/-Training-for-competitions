//https://www.urionlinejudge.com.br/judge/pt/problems/view/1193
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a, b;
int n, clk;

void decToBin(ll dec){
    bool c = false;
    for(int i = 31; i >= 0 ; --i){
        if(dec & (1 << i)){
            printf("1");
            c = true;
        }else if(c) printf("0");
    }
    printf(" bin\n");
}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << "Case " << ++clk << ":\n";
        if(b == "bin") {
            ll dec = stol(a,nullptr,2);
            printf("%lld dec\n", dec);
            printf("%x hex\n", dec);
        }else if(b == "hex"){
            ll dec = stol(a,nullptr,16);
            printf("%lld dec\n", dec);
            decToBin(dec); 
        }else{
            ll dec = stol(a,nullptr,10);
            printf("%x hex\n", dec);
            decToBin(dec);
        }
        cout << endl;
    }

    return 0;
}