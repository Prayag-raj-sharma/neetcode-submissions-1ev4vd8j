class TrieNode {
public:
    array<TrieNode*, 26> children;
    bool isWord;

    TrieNode() : isWord(false) {
        children.fill(nullptr);
    }
};
class PrefixTree {
private:
    TrieNode* root;

    TrieNode* traverse(const string& text) {
        TrieNode* current = root;

        for(char c : text) {
            int index = c - 'a';

            if(current->children[index] == nullptr) {
                return nullptr;
            }

            current = current->children[index];
        }
        return current;
    }

public:
    PrefixTree() {
        root = new TrieNode();  
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(char c: word) {
            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isWord = true;
        
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char c: word) {
            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char c: prefix) {
            int index = c - 'a';

            if(curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};
