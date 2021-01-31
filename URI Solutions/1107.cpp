//https://www.urionlinejudge.com.br/judge/pt/problems/view/1107
//URI 1107 - Escultura à Laser
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, c;
	while(scanf("%d%d", &a, &c) && a+c){
		vector<int> v(c);
		for(int& x : v) scanf("%d", &x);
		int ans = 0;
		for(int h = a; h >= 0 ; --h){
			bool cut = false;
			int maxh = 0, qtd = 0;
			for(int l = 0; l < c ; ++l){
				if(!cut && v[l] < h) qtd++;
				if(v[l] < h) {
					maxh = max(maxh, v[l]);
					cut = true;
				}else if(v[l] >= h){
					cut = false;
				}
			}
			if(qtd){
				ans += qtd*(h-maxh);
			}else break;
			h = maxh+1;
		}
		printf("%d\n", ans);
	}
    return 0;
}
