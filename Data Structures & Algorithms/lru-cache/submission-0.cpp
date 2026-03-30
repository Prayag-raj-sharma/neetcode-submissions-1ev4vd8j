class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node() {
        key = val = -1;
        prev = next = nullptr;
    }

    Node(int k, int value) {
        key = k;
        val = value;
        prev = next = nullptr;
    }
};
class LRUCache {
private:
    map<int, Node*> mpp;
    Node* head;
    Node* tail;
    int cap;

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* nextNode = head->next;
        head->next = node;
        node->next = nextNode;
        nextNode->prev = node;
        node->prev = head;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;  
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];
        int value = node->val;
        deleteNode(node);
        insertAfterHead(node);
        return value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;

            deleteNode(node);
            insertAfterHead(node);
            return;
        }

        if(mpp.size() == cap) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
        }

        Node* newNode = new Node(key, value);
        mpp[key] = newNode;
        insertAfterHead(newNode);
    }
};
