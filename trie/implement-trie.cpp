#include <bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

/*
 * Trie Node
 */
struct TrieNode {
  array<TrieNode *, ALPHABET_SIZE> childrens;
  bool isEnd = false;
};

class Trie {
  private:
    TrieNode *root = getNode();

    /*
     * Returns new trie node (initialized to NULLs)
     */
    TrieNode *getNode() {
      TrieNode *pNode = new TrieNode();

      return pNode;
    }

  public:
    /*
     * If not present, inserts key into trie
     * If the key is prefix of trie node, just marks the leaf node
     */
    void insert(string word) {
      TrieNode *pCrawl = root;

      for (char &ch : word) {
        int index = ch - 'a';

        if (!pCrawl->childrens[index])
          pCrawl->childrens[index] = getNode();

        pCrawl = pCrawl->childrens[index];
      }

      pCrawl->isEnd = true;
    }
    
    /*
     * Returns true if word is present is trie, else false
     */
    bool search(string word) {
      TrieNode *pCrawl = root;

      for (char &ch : word) {
        int index = ch - 'a';

        if (!pCrawl->childrens[index])
          return false;

        pCrawl = pCrawl->childrens[index];
      }

      return pCrawl->isEnd;
    }

    /*
     * Returns true if word starts with a prefix of trie, else false
     */
    bool startsWith(string prefix) {
      TrieNode *pCrawl = root;

      for (char &ch : prefix) {
        int index = ch - 'a';

        if (!pCrawl->childrens[index])
          return false;

        pCrawl = pCrawl->childrens[index];
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