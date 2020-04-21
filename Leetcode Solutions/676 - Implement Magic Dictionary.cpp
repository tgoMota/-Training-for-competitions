class MagicDictionary {
public:
    class Trie{
        public:
        struct Node{
            unordered_map<char, Node*> child;
            bool isLeaf;
            Node() : isLeaf(false){}
        };
        Node* root;
        Trie(){
            root = new Node();
            root->child.clear();
        }
        
        void insert(string data){
            Node *cur = root;
            for(int i = 0; i < data.length() ; ++i){
                Node* nw = cur->child[data[i]];
                if(nw == nullptr){
                    nw = new Node();
                    cur->child[data[i]] = nw;
                }
                cur = cur->child[data[i]];
            }
            cur->isLeaf = true;
        }
        

        bool search(string data){
            if((int)root->child.size() == 0) return false;
            Node *cur = root;
            bool found = false;
            for(int i = 0; i < data.length() ; ++i){
                Node* nw = cur->child[data[i]];
                for(int j = 'a'; j <= 'z' ; ++j){
                    if(j == data[i] || cur->child[j] == nullptr) continue;
                    found = found || dfs(cur->child[j], data, i+1);
                    if(found) return true;
                }
                if(nw == nullptr) return found;
                cur = cur->child[data[i]];
            }
            return false;
        }
        
        bool dfs(Node *no, string& data, int pos){
            Node* cur = no;
            for(int i = pos; i < data.length() ; ++i){
                Node *nw = cur->child[data[i]];
                if(nw == nullptr) return false;
                cur = cur->child[data[i]];
            }
            return cur->isLeaf;
        }
    };
    
    Trie *t;
    /** Initialize your data structure here. */
    MagicDictionary() {
        t = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string s : dict) t->insert(s);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return t->search(word);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */