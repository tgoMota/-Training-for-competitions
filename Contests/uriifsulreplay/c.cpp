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
    vector<char> rm = {'2', '3', '4', '5', '6'};
    vector<char> boa = {'7', 'Q', 'J', 'K', 'A'};
    for(int ti = 1;ti <= t ; ++ti){
        string s;
        cin >> s;
        const int N = s.size();
        int cnt = 0;
        for(int i = 0; i < N ; ++i){
            for(int j = 0; j < rm.size() ; ++j){
                if(s[i] == rm[j]){
                    s.erase(s.begin()+i);
                    i--;
                    cnt++;
                    break;
                }
            }
        }
        int cnt2 = 0;
        // int n7 = 0, Q = 0, J = 0, K = 0, A = 0, count = 0;
        // for(int i = 0; i < s.size() ; ++i){
        //     if(s[i] == '7' && Q+J+K+A+n7 == 0){
        //         n7++;
        //         s.erase(s.begin()+i);
        //         --i;
        //         cnt2++;
        //     }else if(s[i] == 'Q' && Q == 0 && cnt2 == 1){
        //         Q++;
        //         s.erase(s.begin()+i);
        //         --i;
        //         cnt2++;
        //     }else if(s[i] == 'J' && J == 0 && cnt2 == 2){
        //         J++;
        //         s.erase(s.begin()+i);
        //         --i;
        //         cnt2++;
        //     }else if(s[i] == 'K' && K == 0 && cnt2 == 3){
        //         K++;
        //         s.erase(s.begin()+i);
        //         --i;
        //         cnt2++;
        //     }else if(s[i] == 'A' && A == 0 && cnt2 == 4){
        //         s.erase(s.begin()+i);
        //         i = -1;
        //         A = K = J = Q = n7 = 0;
        //         cnt2 = 0;
        //     }
        // }
        //Complete Search
        for(int a = 0; a < N ; ++a){
            bool found = false;
            if(s[a] != '7') continue;
            for(int b = a+1; b < N ; ++b){
                if(s[b] != 'Q') continue;
                for(int c = b+1; c < N ; ++c){
                    if(s[c] != 'J') continue;
                    for(int d = c+1; d < N ; ++d){
                        if(s[d] != 'K') continue;
                        for(int e = d+1; e < N ; ++e){
                            if(s[e] == 'A'){
                                found = true;
                                s.erase(s.begin()+e);
                                break;
                            }
                        }
                        if(found) s.erase(s.begin()+d);
                        break;
                    }
                    if(found) s.erase(s.begin()+c);
                    break;
                }
                if(found) s.erase(s.begin()+b);
                break;
            }
            if(found){
                s.erase(s.begin()+a);
                a--;
            }
            else break;
        }
        cnt+=(int)s.size()+cnt2;
        printf("%d\n", cnt);
    }
    return 0;
}