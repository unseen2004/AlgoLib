#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>

template<typename KeyType>
class TrieNode {
public:
    std::unordered_map<KeyType, TrieNode *> children;
    bool end_of_word;

    TrieNode() : end_of_word(false) {}
    ~TrieNode();
};

template<typename KeyType>
class Trie {
private:
    TrieNode<KeyType> *m_root;

    void print(TrieNode<KeyType> *node, std::basic_string<KeyType> prefix) const;

public:
    Trie();
    ~Trie();
    void insert(const std::basic_string<KeyType> &word);
    bool search(const std::basic_string<KeyType> &word) const;
    void erase(const std::basic_string<KeyType> &word);
    void print() const;
};

#endif // TRIE_H
