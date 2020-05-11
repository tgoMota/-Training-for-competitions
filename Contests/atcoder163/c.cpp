#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
 
int main(){
    int n;
    map<string, int> m;
    cin >> n;
    for(int i = 0; i < n ; ++i){
        string s;
        cin >> s;
        m[s]++;
    }

    printf("%d\n", m.size());
}