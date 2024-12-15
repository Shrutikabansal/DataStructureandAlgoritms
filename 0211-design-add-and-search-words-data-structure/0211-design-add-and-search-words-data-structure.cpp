class TrieNode {
public:
    TrieNode *child[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0;i<26 ;i++){
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
public:

    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for(char c: word){
            if(node->child[c-'a'] == NULL)
                node->child[c-'a'] = new TrieNode();
            node = node->child[c-'a'];
        }

        node->isEnd = true;
    }

    bool searchUtil(TrieNode *node, string word, int index){
        if(node == NULL){
            return false;
        }
        
        if(index == word.size()){
            return node->isEnd;
        }

        char c = word[index];
        if(c == '.'){
            for(TrieNode *child : node->child){
                if(searchUtil(child, word, index+1))
                    return true;
            }
            return false;

        }else{
            int idx = c - 'a';
            if(node->child[idx] == NULL){
                return false;
            }
          
            return searchUtil(node->child[idx], word, index+1);

        }

    }

    bool search(string word) {
        TrieNode *node = root;

        return searchUtil(node, word, 0);

        // for(char c: word){
        //     if(c == '.'){

        //     }
           
        //     node = node->child[c-'a'];
        // }

        // return node->isEnd;

        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */