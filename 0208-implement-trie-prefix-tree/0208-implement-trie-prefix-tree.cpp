class TrieNode{
public: 
    TrieNode * child[26];
    bool wordEnd;

    TrieNode(){
        wordEnd = false;
        for(int i =0;i< 26;i++){
            child[i] = nullptr;
        }
    }
};

class Trie {
public:

    TrieNode *root;

    Trie() {
        root = new TrieNode();
        
    }
    
    void insert(string word) {

        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node->child[idx] == NULL){
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->wordEnd = true;
        
    }
    
    bool search(string word) {

        TrieNode *node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node->child[idx] == NULL){
                return false;
            }
            node = node->child[idx];
        }

        return node->wordEnd;
        
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(char c : prefix){
            int idx = c - 'a';
            if(node->child[idx] == NULL){
                return false;
            }
            node = node->child[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */