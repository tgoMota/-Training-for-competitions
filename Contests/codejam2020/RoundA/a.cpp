#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;

class Trie{
    public:
        struct Node{
            bool end;
            unordered_map<char, Node*> child;
            Node() : end(false){}
        };

        Node *root;
        Trie(){
            root = new Node();
        }

        void insert(string data){
            Node *current = root;
            for(int i = 0; i < data.length() ; ++i){
                Node *nw = current->child[data[i]];
                if(nw == nullptr){
                    nw = new Node();
                    current->child[data[i]] = nw;
                }
                current = nw;
            }
            current->end = true;
        }

        bool search(string data){
            Node *current = root;
            for(int i = 0; i < data.length() ; ++i){
                Node *nw = current->child[data[i]];
                if(nw == nullptr) return false;
                current = nw;
            }
            return current->end;
        }

        void remove(string data){
            remove2(root, data, 0);
        }

        bool remove2(Node* current, string& data, int index){
            if(index == data.length()){
                if(!current->end) return false;
                current->end = false;
                return current->child.size() == 0;
            }

            Node* nw = current->child[data[index]];
            if(nw == nullptr) return false;
            bool shouldRemove = remove2(nw, data, index+1);

            if(shouldRemove){
                current->child.erase(data[index]);
                return current->child.size() == 0;
            }

            return false;
        }
};

int main(){
    int t, n;
    cin >> t;
    string a;
    for(int ti = 1;ti <= t ; ++ti){
        cin >> n;
        Trie* t;
        for(int i = 0; i < n ; ++i) {
            cin >> a;
            t->insert(a);
        }
        
        

        printf("Case #%d: %d %d %d\n", ti, k, r, c);
    }

    return 0;
}