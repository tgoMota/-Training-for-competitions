//https://www.urionlinejudge.com.br/judge/pt/problems/view/1873
//URI 1873 - Pedra-papel-tesoura-lagarto-Spock
#include <bits/stdc++.h>
using namespace std;
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    int t;
    cin >> t;
    map<string,set<string>> mp;
    mp["tesoura"].insert("papel");
    mp["papel"].insert("pedra");
    mp["pedra"].insert("lagarto");
    mp["lagarto"].insert("spock");
    mp["spock"].insert("tesoura");
    mp["tesoura"].insert("lagarto");
    mp["lagarto"].insert("papel");
    mp["papel"].insert("spock");
    mp["spock"].insert("pedra");
    mp["pedra"].insert("tesoura");
    for(int ti = 1; ti <= t ; ++ti){
        bool rajesh = false, sheldon = false;
        string a, b;
        cin >> a >> b;
        if(mp[a].count(b)) rajesh = true;
        if(mp[b].count(a)) sheldon = true;

        if((rajesh && sheldon) || (!rajesh && !sheldon)) cout << "empate\n";
        else if(rajesh) cout << "rajesh\n";
        else cout << "sheldon\n";
    }
    return 0;
}

