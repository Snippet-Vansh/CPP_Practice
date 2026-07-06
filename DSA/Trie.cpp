#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word
    void insert(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == NULL)
                curr->child[index] = new TrieNode();

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    // Search a complete word
    bool search(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->child[index] == NULL)
                return false;

            curr = curr->child[index];
        }

        return curr->isEnd;
    }

    // Check if prefix exists
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->child[index] == NULL)
                return false;

            curr = curr->child[index];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << "Search apple: " << trie.search("apple") << endl;
    cout << "Search app: " << trie.search("app") << endl;
    cout << "Search bat: " << trie.search("bat") << endl;
    cout << "Search ball: " << trie.search("ball") << endl;

    cout << "StartsWith ap: " << trie.startsWith("ap") << endl;
    cout << "StartsWith ba: " << trie.startsWith("ba") << endl;
    cout << "StartsWith cat: " << trie.startsWith("cat") << endl;

    return 0;
}