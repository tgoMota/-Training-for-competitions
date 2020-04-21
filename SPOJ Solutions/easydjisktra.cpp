//https://www.spoj.com/problems/EZDIJKST/
#include <bits/stdc++.h>
using namespace std;

int clk, n, m, dist[10005];
vector<pair<int,int> > adj[10002];

void djikstra(int v){
	for(int i = 1; i <= n ; ++i) dist[i] = -1;
	set<pair<int,int> > fila;
	fila.insert({0,v});
	pair<int,int> aux;
	while(!fila.empty()){
		aux = *fila.begin();
		fila.erase(fila.begin());
		int distv = aux.first, ver = aux.second;
		if(dist[ver] != -1) continue;
		dist[ver] = distv;
		for(auto vis : adj[ver]){
			if(dist[vis.first] != -1) continue;
			fila.insert({distv + vis.second, vis.first}); 
		}
	}
}

int main(){
	int origem, destino;
	cin >> clk;
	while(clk-->0){
		cin >> n >> m;
		for(int i = 1; i <= m; ++i){
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({b,c});
		}
		cin >> origem >> destino;
		djikstra(origem);
		if(dist[destino] != -1) cout << dist[destino] << endl;
		else cout << "NO\n";
		for(int i = 1; i <= n ; ++i) adj[i].clear();
	}

return 0;
}
