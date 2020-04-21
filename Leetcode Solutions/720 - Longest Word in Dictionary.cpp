class Solution {
public:
    class Trie{
        public:
        struct Node{
            unordered_map<char,Node*> child;
            bool isLeaf;
            Node(): isLeaf(false){}
        };
        
        Node* root;
        vector<string> ans;
        Trie(){
            root = new Node();
        }
        
        void insert(string data){
            Node* current = root;
            for(int i = 0; i < data.length() ; ++i){
                Node* nw = current->child[data[i]];
                if(nw == nullptr){
                    nw = new Node();
                    current->child[data[i]] = nw;
                }
                current = current->child[data[i]];
            }
            current->isLeaf = true;
        }
        
        void dfs(Node* node, string& ans){
            if(node == nullptr) return;
            int maxheight = 0;
            char maxchar;
            for(int i = 'z' ; i >= 'a' ; --i){
               Node* nw = node->child[i];
               if(nw == nullptr) continue;
               int h = height(nw);
               if(h >= maxheight){
                   maxheight = h;
                   maxchar = i;
               }
            }
            if(!maxheight) return;
            ans+=maxchar;
            dfs(node->child[maxchar], ans);
        }
        
        int height(Node* node){
            if(!node->isLeaf) return 0;
            int cnt = 1;
            for(int i = 'z' ; i >= 'a' ; --i){
                Node* nw = node->child[i];
                if(nw == nullptr) continue;
                cnt = max(cnt, 1+height(nw));
            }
            return cnt;
        }
        
        string searchLongestWord(){
            string ans = "";
            dfs(root, ans);
            return ans;
        }
       
    };
    
    string longestWord(vector<string>& words) {
        Trie *t = new Trie();
        for(string x : words) t->insert(x);
        string ans = t->searchLongestWord();
        return ans;
    }
};