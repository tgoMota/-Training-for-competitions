#include <bits/stdc++.h>
#define oo 0x3f3f3f3f
using namespace std;
typedef pair<int,int> ii;
const int N = 404;
ii t[N];
int distA[N][N][N], distB[N][N][N];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++){
		scanf("%d", &t[i].first);
		t[i].second = i;
	}
	sort(t+1, t+n+1);
	memset(distA, oo, sizeof distA);
	memset(distB, oo, sizeof distB);
	for (int i=0; i<m; i++){
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);
		distA[1][u][v] = min(distA[1][u][v], d);
		distA[1][v][u] = distA[1][u][v];
		distB[1][u][v] = distB[1][v][u] = distA[1][u][v];
	}
	int k = 1;
	for (int cnt=1; cnt<=n; cnt++){
		if(cnt != 1 && t[cnt-1].first != t[cnt].first) k++;
		int u = t[cnt].second;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distA[k][i][j] = min(distA[k][i][j], distA[k][i][u] + distA[k][u][j]);
				distA[k+1][i][j] = distA[k][i][j];
			}
		}
	}
	for (int cnt = k+1; cnt <= n; cnt++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distA[cnt][i][j] = distA[cnt-1][i][j];
			}
		}
	}
	sort(t+1, t+n+1, greater<ii>());
	k = 1;
	for (int cnt=1; cnt<=n; cnt++){
		if(cnt != 1 && t[cnt-1].first != t[cnt].first) k++;
		int u = t[cnt].second;
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distB[k][i][j] = min(distB[k][i][j], distB[k][i][u] + distB[k][u][j]);
				distB[k+1][i][j] = distB[k][i][j];
			}
		}
	}
	for (int cnt = k+1; cnt <= n; cnt++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				distB[cnt][i][j] = distB[cnt-1][i][j];
			}
		}
	}
	int q;
	scanf("%d", &q);
	while (q-- > 0){
		int u, v, k, op;
		scanf("%d %d %d %d", &u, &v, &k, &op);
		if(op == 0) {
			printf("%d\n", (distA[k][u][v] != oo) ? distA[k][u][v] : -1);
		}
		else {
			printf("%d\n", (distB[k][u][v] != oo) ? distB[k][u][v] : -1);
		}
	}
}