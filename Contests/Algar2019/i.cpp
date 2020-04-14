#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a, b, c, d;
    while(scanf("%lld%lld%lld%lld", &a, &b, &c, &d) != EOF){
        string rest = to_string((double)c/d);
        int who = 1, i;
        for(i = 0; rest[i] != '.' ; ++i);

        for(i += 1; i < rest.size() ; ++i){
            if(rest[i] - '0' == a) who = 0; //Reluew
            if(rest[i] - '0' == b) who = 2; //Ovatsug
            if(who != 1) break;
        }

        if(a == b || who == 1) printf("Empate\n");
        else if(who == 2) printf("Ovatsug\n");
        else printf("Reluew\n");
    }


    return 0;
}