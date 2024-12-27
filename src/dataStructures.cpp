#include <vector>
#include <functional>
#include <unordered_map>
#include <stdexcept>
#include <iostream>

template<typename T>
struct node {
    T m_val;
    node<T> *m_next;

    node(T val) : m_val(val), m_next(nullptr) {
    }
};

template<typename T>
struct Node {
    T val;
    Node<T> *next;
    Node<T> *prev;

    Node(T v, Node<T> *next = nullptr, Node<T> *prev = nullptr)
        : val(v), next(next), prev(prev) {
    }
};


template<typename KeyType>
class TrieNode {
public:
    std::unordered_map<KeyType, TrieNode *> children;
    bool end_of_word;

    TrieNode() : end_of_word(false) {
    }

    ~TrieNode() {
        for (auto &pair: children) {
            delete pair.second;
        }
    }
};

template<typename KeyType>
class Trie {
private:
    TrieNode<KeyType> *m_root;

    void print(TrieNode<KeyType> *node, std::basic_string<KeyType> prefix) const {
        if (node->end_of_word) {
            std::cout << prefix << "\n";
        }
        for (const auto &pair: node->children) {
            print(pair.second, prefix + pair.first);
        }
    }

public:
    Trie() {
        m_root = new TrieNode<KeyType>();
    }

    ~Trie() {
        delete m_root;
    }

    void insert(const std::basic_string<KeyType> &word) {
        TrieNode<KeyType> *node = m_root;
        for (const KeyType &key: word) {
            if (node->children.find(key) == node->children.end()) {
                node->children[key] = new TrieNode<KeyType>();
            }
            node = node->children[key];
        }
        node->end_of_word = true;
    }

    bool search(const std::basic_string<KeyType> &word) const {
        TrieNode<KeyType> *node = m_root;
        for (const KeyType &key: word) {
            if (node->children.find(key) == node->children.end()) {
                return false;
            }
            node = node->children[key];
        }
        return node->end_of_word;
    }

    void erase(const std::basic_string<KeyType> &word) {
        TrieNode<KeyType> *node = m_root;
        for (const KeyType &key: word) {
            if (node->children.find(key) == node->children.end()) {
                return;
            }
            node = node->children[key];
        }
        if (node->end_of_word) {
            node->end_of_word = false;
        }
    }

    void print() const {
        print(m_root, std::basic_string<KeyType>());
    }
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

    ~LRU_Cache() {
        // Cleanup all allocated nodes
        NodePtr current = m_head;
        while (current) {
            NodePtr to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }

    void update(K key, V value) {
        // Check if the key exists
        if (look_up.find(key) != look_up.end()) {
            NodePtr node = look_up[key];
            node->value = value; // Update value
            detach(node);
            prepend(node);
        } else {
            // Insert a new node
            if (m_length == m_capacity) {
                trimCache();
            }
            NodePtr node = new Node<V>(value);
            prepend(node);
            look_up[key] = node;
            reverse_look_up[node] = key;
            ++m_length;
        }
    }

    V get(K key) {
        if (look_up.find(key) != look_up.end()) {
            NodePtr node = look_up[key];
            detach(node);
            prepend(node);
            return node->value;
        }
        throw std::out_of_range("Key not found");
    }

private:
    void detach(NodePtr node) {
        if (node->next) {
            node->next->prev = node->prev;
        }
        if (node->prev) {
            node->prev->next = node->next;
        }
        if (node == m_head) {
            m_head = node->next;
        }
        if (node == m_tail) {
            m_tail = node->prev;
        }
        node->next = nullptr;
        node->prev = nullptr;
    }

    void prepend(NodePtr node) {
        if (!m_head) {
            m_head = m_tail = node;
            return;
        }
        node->next = m_head;
        m_head->prev = node;
        m_head = node;
    }

    void trimCache() {
        if (!m_tail) return;

        NodePtr node_to_remove = m_tail;
        K key_to_remove = reverse_look_up[node_to_remove];

        detach(node_to_remove);

        look_up.erase(key_to_remove);
        reverse_look_up.erase(node_to_remove);

        delete node_to_remove;
        --m_length;
    }
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

    ~Heap() {
        while (length > 0) {
            deleteTop();
        }
    }

    void insert(T n) {
        data.push_back(n);
        heapifyUp(length);
        ++length;
    }

    T deleteTop() {
        if (length == 0) {
            return T();
        }

        T out = data[0];

        --length;
        if (length == 0) {
            data.pop_back();
            return out;
        }

        data[0] = data[length];
        data.pop_back();
        heapifyDown(0);

        return out;
    }

private:
    int parent(int idx) const {
        return (idx - 1) / 2;
    }

    int leftChild(int idx) const {
        return 2 * idx + 1;
    }

    int rightChild(int idx) const {
        return 2 * idx + 2;
    }

    void heapifyUp(int idx) {
        if (idx == 0) return;

        int p = parent(idx);
        if (compare(data[p], data[idx])) {
            std::swap(data[p], data[idx]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int idx) {
        int lIdx = leftChild(idx);
        int rIdx = rightChild(idx);
        int extreme = idx;

        if (lIdx < length && compare(data[extreme], data[lIdx])) {
            extreme = lIdx;
        }

        if (rIdx < length && compare(data[extreme], data[rIdx])) {
            extreme = rIdx;
        }

        if (extreme != idx) {
            std::swap(data[idx], data[extreme]);
            heapifyDown(extreme);
        }
    }

    bool compare(T a, T b) const {
        return isMinHeap ? std::greater<T>()(a, b) : std::less<T>()(a, b);
    }
};


template<typename T>
class LinkedList {
    node<T> *m_head;

public:
    LinkedList() : m_head(nullptr) {
    }

    ~LinkedList() {
        while (m_head) {
            pop();
        }
    }

    void add(T val) {
        node<T> *newNode = new node<T>(val);
        if (m_head == nullptr) {
            m_head = newNode;
        } else {
            node<T> *tmp = m_head;
            while (tmp->m_next) {
                tmp = tmp->m_next;
            }
            tmp->m_next = newNode;
        }
    }

    void pop() {
        if (m_head == nullptr) {
            return;
        } else if (m_head->m_next == nullptr) {
            delete m_head;
            m_head = nullptr;
        } else {
            node<T> *tmp = m_head;
            while (tmp->m_next->m_next) {
                tmp = tmp->m_next;
            }
            delete tmp->m_next;
            tmp->m_next = nullptr;
        }
    }
};


template<typename T>
class DoubleLinkedList {
    Node<T> *m_head;
    Node<T> *m_tail;

public:
    DoubleLinkedList() : m_head(nullptr), m_tail(nullptr) {
    }

    ~DoubleLinkedList() {
        while (m_tail) {
            pop();
        }
    }

    void push(T val) {
        Node<T> *newNode = new Node<T>(val, nullptr, nullptr);
        if (m_tail == nullptr) {
            m_head = m_tail = newNode;
        } else {
            m_tail->next = newNode;
            newNode->prev = m_tail;
            m_tail = newNode;
        }
    }

    void pop() {
        if (m_tail == nullptr) {
            return;
        } else if (m_tail == m_head) {
            delete m_tail;
            m_tail = m_head = nullptr;
        } else {
            Node<T> *toDel = m_tail;
            m_tail = m_tail->prev;
            m_tail->next = nullptr;
            delete toDel;
        }
    }
};


