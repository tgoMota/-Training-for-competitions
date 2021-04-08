#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define MAXN 100010
char T[MAXN], P[MAXN];
int n, m;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN], phi[MAXN];
int LCP[MAXN], PLCP[MAXN];

void countSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void makeSA() {
	int i, k, r;
	for (i = 0; i < n; i++) {
		RA[i] = T[i];
		SA[i] = i;
	}
	for (k = 1; k < n; k <<= 1) {
		countSort(k);
		countSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] =
					(RA[SA[i]] == RA[SA[i - 1]]
							&& RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
	}
}

void compLCP() {
	int i, L;
	phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		phi[SA[i]] = SA[i - 1];
	for (i = L = 0; i < n; i++) {
		if (phi[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while (T[i + L] == T[phi[i] + L])
			L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

bool comp(ii a, ii b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

struct minqueue{
    deque<pair<ii,int>> q;
    int cnt_added, cnt_removed;
    minqueue(){
        cnt_added = cnt_removed = 0;
    }
    void push(ii new_element){
        while (!q.empty() && comp(q.back().first, new_element)) q.pop_back();
        q.push_back(make_pair(new_element, cnt_added));
        cnt_added++;
    }

    ii getMin(){
        return q.front().first;
    }

    void pop(){
        if (!q.empty() && q.front().second == cnt_removed) 
            q.pop_front();
        cnt_removed++;
    }
};

void max_self(ii& a, ii b){
    if(a.first == b.first && a.second > b.second) a = b;
    else if(a.first < b.first) a = b;
}

int main() {
		int k;
		fgets(T, sizeof(T), stdin);
		strcat(T, "$");
		n = strlen(T);
		scanf("%d", &k);
		makeSA();
		compLCP();
		minqueue q;
		for(int i = 0; i < min(k-1,n) ; ++i){
        	q.push({LCP[i], SA[i]});
		}
		ii best = {0,0};
		for(int i = k-1; i < n ; ++i){
			max_self(best, q.getMin());
			q.pop();
			q.push({LCP[i], SA[i]});
		}
		max_self(best, q.getMin());
		if(best.first > 0) {
			for(int i = best.second; i < best.second + best.first ; ++i) cout << T[i];
			cout << '\n';
		}
		else cout << ":)\n";
		

	return 0;
}