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
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, a, b;
        cin >> n >> a >> b;
        string ans = "";
        for(int i = 0, cnt = 0; i < n; ++i){
            char ch = 'a'+cnt;
            if(cnt >= b){
                ans+='a';
            }else{
                ans+=ch;
            }      
            cnt++;
            if(cnt == a) cnt = 0;
        }
        cout << ans << endl;
    }
    return 0;
}