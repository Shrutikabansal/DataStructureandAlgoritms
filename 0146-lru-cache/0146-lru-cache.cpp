class LRUCache {
public:

    class Node{
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){
        Node* temp = head->next;

        head->next = node;
        temp->prev = node;

        node->next = temp;
        node->prev = head;
    }

    void deleteNode(Node* node){
        Node* previ = node->prev;
        Node* nextt = node->next;

        previ->next = nextt;
        nextt->prev = previ;
    }
    
    int get(int key) {

        if(m.find(key) == m.end()){
            return -1;
        }

        Node* data = m[key];
        int ans = data->val;
        m.erase(key);
        deleteNode(data);
        addNode(data);

        m[key] = head->next;
        return ans;

        
    }
    
    void put(int key, int value) {


        if(m.find(key)!= m.end()){
            Node* data = m[key];
            m.erase(key);
            deleteNode(data);
        }

        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

         addNode(new Node(key, value));
         m[key] = head->next;


        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */