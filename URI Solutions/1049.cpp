//https://www.urionlinejudge.com.br/judge/pt/problems/view/1049
//URI 1049 - Animal
#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c, ans;
    cin >> a >> b >> c;

    if(a == "vertebrado"){
        if(b == "ave"){
            if(c == "carnivoro") ans = "aguia";
            else ans = "pomba";
        }else{
            if(c == "onivoro") ans = "homem";
            else ans = "vaca";
        }
    }else{
        if(b == "inseto"){
            if(c == "hematofago") ans = "pulga";
            else ans = "lagarta";
        }
        else{
            if(c == "hematofago") ans = "sanguessuga";
            else ans = "minhoca";
        }
    }

    cout << ans << endl;


    return 0;
}