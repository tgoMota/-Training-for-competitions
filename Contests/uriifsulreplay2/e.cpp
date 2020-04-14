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
        string s;
        cin >> s;
        string ans = s;
        sort(ans.begin(), ans.end());
            if(ans[0] == '0'){
                for(int j = 1; j < ans.size() ; ++j){
                    if(ans[j] != '0'){
                        char ch = ans[j];
                        ans.erase(ans.begin()+j);
                        ans.insert(ans.begin(), ch);
                        break;
                    } 
                }
            }
        printf("%s\n", ans.c_str());
    }
    return 0;
}