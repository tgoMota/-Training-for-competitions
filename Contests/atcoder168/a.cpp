#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    int t = 1;
    for(int ti = 1; ti <= t ; ++ti){
        int d;
        scanf("%d", &d);
        int r = d%10;
        if(r == 2 || r == 4 || r == 5 || r == 7 || r == 9) printf("hon\n");
        else if(r == 0 || r == 1 || r == 6 || r == 8) printf("pon\n");
        else if(r == 3) printf("bon\n");
    }
    return 0;
}