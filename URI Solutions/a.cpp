#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
#define oo 0x3f3f3f3f
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
typedef pair<int,int> ii;
const int MAXN = 500010;
int n;
string str;
int SA[MAXN], ord[MAXN], nord[MAXN], cnt[MAXN], aux[MAXN];
int rev[MAXN], LCP[MAXN];
void getSA() {
    for (int i = 0; i < n; i++) ord[i] = str[i];
    int p = 1, pnt = 1;
    while (1) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) cnt[ord[min(i + p, n)]]++;
        for (int i = 1; i <= max(n, 255); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) aux[--cnt[ord[min(i + p, n)]]] = i;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) cnt[ord[i]]++;
        for (int i = 1; i <= max(n, 255); i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--) SA[--cnt[ord[aux[i]]]] = aux[i];
        if (pnt == n) break;
        pnt = 1;
        nord[SA[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (ord[SA[i - 1]] != ord[SA[i]] || ord[SA[i - 1] + p] != ord[SA[i] + p]) pnt++;
            nord[SA[i]] = pnt;
        }
        memcpy(ord, nord, sizeof(int) * n);
        p <<= 1;
    }
}
void getLCP() {
    for (int i = 0; i < n; i++) rev[SA[i]] = i;
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rev[i]) {
            int prv = SA[rev[i] - 1];
            while (str[prv + h] == str[i + h]) h++;
            LCP[rev[i]] = h;
        }
        h = max(h - 1, 0);
    }
}
string line;

struct minqueue{
    deque<pair<int,int>> q;
    int cnt_added, cnt_removed;
    minqueue(){
        clear();
    }
    void push(int new_element){
        while (!q.empty() && q.back().first > new_element) q.pop_back();
        q.push_back(make_pair(new_element, cnt_added));
        cnt_added++;
    }

    int getMin(){
        return q.front().first;
    }

    void pop(){
        if (!q.empty() && q.front().second == cnt_removed) q.pop_front();
        cnt_removed++;
    }
    void clear(){
        cnt_added = cnt_removed = 0;
        q.clear();
    }
};


int main(){
    int k;
    getline(cin, line);

    cin >> k;
    if(k > (int)line.size()){
        cout << ":)\n";
        return 0;
    }
    if(k == 1){
        cout << line << '\n';
        return 0;
    }
    getSA();
    minqueue q;
    int best = 0;
    for(int i = 0; i < (int)line.size() ; ++i){
        if(i < k-1){
            q.push(LCP[i]);
            continue;
        }
        best = max(best, q.getMin());
        q.pop();
        q.push(LCP[i]);
    }
    best = max(best, q.getMin());
    int minpos = oo;
    for(int i = 0; i < (int)line.size() && best ; ++i){
       if(LCP[i] == best){
         while(i < (int)line.size() && LCP[i] >= best) minpos = min(minpos, min(SA[i-1], SA[i])), ++i;
       }
    }
    if(best) cout << line.substr(minpos, best) << '\n';
    else cout << ":)\n";
    return 0;
}