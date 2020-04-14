#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;

int main(){
    int t;
    cin >> t;
    for(int ti = 1;ti <= t ; ++ti){
        string s;
        cin >> s;
        int q = 0, j = 0, k = 0, a = 0;
        for(int i = 0; i < s.size() ; ++i){
            if(s[i] == 'A') a++;
            else if(s[i] == 'J') j++;
            else if(s[i] == 'K') k++;
            else if(s[i] == 'Q') q++;
        }

        if(q && j && k && a) printf("Aaah muleke\n");
        else printf("Ooo raca viu\n");
    }
    return 0;
}