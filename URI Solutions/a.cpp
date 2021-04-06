#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
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
vector<int> sort_cyclic_shifts(string const& s) {
    int n = (int)s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1]; //representa o rank de cada caractere
    for (int i = 0; i < n; i++){
        p[--cnt[s[i]]] = i; // p[i] representa a posicao do caractere em s que ocupa a i'nésima ordem lexicografica
    }
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++){
            cnt[c[pn[i]]]++;
        }
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp(string const& s, vector<int> const& p) {
    int n = (int)s.size();
    vector<int> rank(n+1, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n+1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n-1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
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

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }

ii LCS() {                 // returns a pair (the LCS length and its index)
  int i, idx = 0, maxLCP = -1;
  for (i = 1; i < n; i++)                         // O(n), start from i = 1
    if (owner(SA[i]) != owner(SA[i-1]) && LCP[i] > maxLCP)
      maxLCP = LCP[i], idx = i;
  return ii(maxLCP, idx);
}

int main(){
    int k;
    string line;
    getline(cin, line);
    cin >> k;
    vector<int> suf_array = suffix_array_construction(line);
    const int N = (int)suf_array.size();
    vector<int> lp = lcp(line, suf_array);

    minqueue q;
    for(int i = 0; i < min(k-1,N) ; ++i){
        q.push({lp[i], suf_array[i]});
    }
    ii best = {0,0};
    for(int i = k-1; i < N ; ++i){
        max_self(best, q.getMin());
        q.pop();
        q.push({lp[i], suf_array[i]});
    }
    max_self(best, q.getMin());
    if(best.first > 0) cout << line.substr(best.second, best.first) << '\n';
    else cout << ":)\n";
    return 0;
}