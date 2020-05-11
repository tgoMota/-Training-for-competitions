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
    string a, b;
    cin >> a;
    cin >> b;
    if(a == b.substr(0,b.size()-1)) printf("Yes\n");
    else printf("No\n");
    return 0;
}