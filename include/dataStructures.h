#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <vector>

template<typename KeyType>
struct TrieNode {
    std::unordered_map<KeyType, TrieNode *> children;
    bool end_of_word;

    TrieNode() : end_of_word(false) {
    }
};

template<typename KeyType>
class Trie {
private:
    TrieNode<KeyType> *m_root;

public:
    Trie() : m_root(new TrieNode<KeyType>()) {
    }

    ~Trie();

    void insert(const std::basic_string<KeyType> &word);

    bool search(const std::basic_string<KeyType> &word) const;

    void remove(const std::basic_string<KeyType> &word);

    void print() const;

private:
    void remove(TrieNode<KeyType> *node, const std::basic_string<KeyType> &word, int depth);

    void print(TrieNode<KeyType> *node, std::basic_string<KeyType> prefix) const;
};


template<typename K, typename V>
class LRU_Cache {
    using NodePtr = Node<V> *;

    int m_length;
    NodePtr m_head;
    NodePtr m_tail;
    const int m_capacity;
    std::unordered_map<K, NodePtr> look_up;
    std::unordered_map<NodePtr, K> reverse_look_up;

public:
    LRU_Cache(int capacity = 10)
        : m_capacity(capacity), m_length(0), m_head(nullptr), m_tail(nullptr) {
    }

    ~LRU_Cache();

    void update(K key, V value);

    V get(K key);

private:
    void detach(NodePtr node);

    void prepend(NodePtr node);

    void trimCache();
};


template<typename T>
class Heap {
private:
    int length;
    std::vector<T> data;
    bool isMinHeap;

public:
    Heap(bool minHeap = true) : length(0), data(), isMinHeap(minHeap) {
    }

    ~Heap();

    void insert(T n);

    T deleteTop();

private:
    int parent(int idx) const;

    int leftChild(int idx) const;

    int rightChild(int idx) const;

    void heapifyUp(int idx);

    void heapifyDown(int idx);

    bool compare(T a, T b) const;
};

template<typename T>
struct Node {
    T m_val;
    Node<T> *m_next;

    Node(T val) : m_val(val), m_next(nullptr) {
    }
};

template<typename T>
class LinkedList {
private:
    Node<T> *m_head;

public:
    LinkedList() : m_head(nullptr) {
    }

    ~LinkedList();

    void add(T val);

    void pop();
};

template<typename T>
struct DNode {
    T val;
    DNode<T> *next;
    DNode<T> *prev;

    DNode(T v, DNode<T> *next = nullptr, DNode<T> *prev = nullptr)
        : val(v), next(next), prev(prev) {
    }
};

template<typename T>
class DoubleLinkedList {
private:
    DNode<T> *m_head;
    DNode<T> *m_tail;

public:
    DoubleLinkedList() : m_head(nullptr), m_tail(nullptr) {
    }

    ~DoubleLinkedList();

    void push(T val);

    void pop();
};

#endif
