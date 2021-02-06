//https://www.urionlinejudge.com.br/judge/pt/problems/view/2087
//URI 2087 - Conjuntos Bons e Ruins
#include <bits/stdc++.h>
using namespace std;
struct Node{
    bool end;
    struct Node *m[26];
    Node(){
        end = false;
		for(int i = 0; i < 26 ; ++i) m[i] = nullptr;
    }
};

struct Trie{
    Node *root;
    Trie(){
        root = new Node();
    }

    bool insert(string s){
        Node* cur = root;
        const int N = (int)s.size();
        for(int i = 0; i < N ; ++i){
			int ch = s[i]-'a';
			if(cur->end) return false;
            if(cur->m[ch] == nullptr){
                Node *nw = new Node();
                cur->m[ch] = nw;
			}
			cur = cur->m[ch];
        }
		bool has = false;
		for(int i = 0; i < 26 ; ++i){
			if(cur->m[i] != nullptr) has = true;
		}
		if(cur->end || has) return false;
        return cur->end = true;
    }

};

int main(){
	int n;
	while(scanf("%d", &n) && n){
		Trie t = Trie();
		bool ok = true;
		for(int i = 0; i < n ; ++i){
			string a;
			cin >> a;
			if(!ok) continue;
			if(!t.insert(a)) ok = false;
		}
		if(ok) printf("Conjunto Bom\n");
		else printf("Conjunto Ruim\n");
	}
	return 0;
}