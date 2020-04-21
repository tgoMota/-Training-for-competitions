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
              
        string prefix(string& data){
            Node* cur = root;
            string pfix = "";
            for(int i = 0; i < data.length() ; ++i){
                Node * nw = cur->child[data[i]];
                if(nw != nullptr){
                    pfix+=data[i];
                    if(nw->isLeaf) return pfix;
                }else return data;
                cur = cur->child[data[i]];
            }
            return data;
        }
    };
    
    string replaceWords(vector<string>& dict, string sen) {
        Trie *t = new Trie();
        for(string s : dict) t->insert(s);
        vector<string> newSen;
        for(int i = 0, last = 0; i < sen.length() ;i++ ){
            if(sen[i] == ' ' || i == sen.length()-1) {
                if(i == sen.length() - 1) i++;
                newSen.push_back(sen.substr(last,i-last));
                while(i < sen.length()-1 && sen[i+1] == ' ') i++;
                last = i+1;
            }
        }
        string ans = "";
        for(int i = 0; i < newSen.size() ; ++i){
            string pref = t->prefix(newSen[i]);
            ans+=pref;
            if(i != newSen.size()-1) ans+= " ";
        }
        return ans;
    }
};