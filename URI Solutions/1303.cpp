//https://www.urionlinejudge.com.br/judge/pt/problems/view/1303
//URI 1303 - Spurs Rocks
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;

struct Team{
    int id;
    int points;
    int goalsMarked;
    int goalsReceived;

    Team(){}

    Team(int _id){
        id = _id;
        points = 0;
        goalsMarked = 0;
        goalsReceived = 0;
    }
    

    double getAverage(){
        if(goalsReceived == 0) return (double)goalsMarked;
        return goalsMarked/(double)goalsReceived;
    }
};

int main(){
    int n, ti = 0;
    while(scanf("%d", &n) && n){
        if(ti) printf("\n");
        vector<Team> v(n);
        for(int i = 0; i < n ; ++i){
            v[i] = Team(i+1);
        }
        for(int i = 0; i < n*(n-1)/2 ; ++i){
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if(d > b){
                swap(a, c);
                swap(b, d);
            }
            v[a-1].goalsMarked+=b;
            v[a-1].goalsReceived+=d;
            v[a-1].points+=2;
            v[c-1].goalsMarked+=d;
            v[c-1].goalsReceived+=b;
            v[c-1].points++;
        }

        sort(v.begin(), v.end(), [&](auto& ta, auto& tb){
            if(ta.points > tb.points) return true;
            else if(ta.points < tb.points) return false;
            else if(ta.getAverage() > tb.getAverage()) return true;
            else if(ta.getAverage() < tb.getAverage()) return false;
            else if(ta.goalsMarked > tb.goalsMarked) return true;
            else if(ta.goalsMarked < tb.goalsMarked) return false;
            else if(ta.id < tb.id) return true;
            else return false;
        });
        printf("Instancia %d\n", ++ti);
        for(int i = 0, j = 0; i < n ; ++i){
            if(j++) printf(" ");
            printf("%d", v[i].id);
        }
         printf("\n");
    }
    return 0;
}