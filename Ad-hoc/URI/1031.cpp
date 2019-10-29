//https://www.urionlinejudge.com.br/judge/pt/problems/view/1031
//URI 1031 - Crise de Energia
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s, cnt, now;
    while(scanf("%d", &n) && n){
        bool vst[n];
        for(int i = 1; ; ++i){
            memset(vst, false, sizeof(vst));
            s = i, cnt = 0, now = 0;
            while(now != 12 && cnt <= n){
                vst[now] = true;
                cnt++;
                for(int k = 1 ; k <= s ; ++k){
                    now = (now+1)%n;
                    while(vst[now] && cnt <= n) now = (now+1)%n;
                }
            }
            if(cnt == n-1) break;
        }
        printf("%d\n", s);
    }

    return 0;
}