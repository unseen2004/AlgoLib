#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <unordered_map>
#include "Node.h"

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
    LRU_Cache(int capacity = 10);
    ~LRU_Cache();
    void update(K key, V value);
    V get(K key);

private:
    void detach(NodePtr node);
    void prepend(NodePtr node);
    void trimCache();
};

#endif // LRU_CACHE_H
