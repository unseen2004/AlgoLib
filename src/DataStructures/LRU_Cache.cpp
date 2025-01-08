#include "../../include/DataStructures/LRU_Cache.h"

template<typename K, typename V>
LRU_Cache<K, V>::LRU_Cache(int capacity)
        : m_capacity(capacity), m_length(0), m_head(nullptr), m_tail(nullptr) {}

template<typename K, typename V>
LRU_Cache<K, V>::~LRU_Cache() {
    NodePtr current = m_head;
    while (current) {
        NodePtr to_delete = current;
        current = current->next;
        delete to_delete;
    }
}

template<typename K, typename V>
void LRU_Cache<K, V>::update(K key, V value) {
    if (look_up.find(key) != look_up.end()) {
        NodePtr node = look_up[key];
        node->value = value;
        detach(node);
        prepend(node);
    } else {
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

template<typename K, typename V>
V LRU_Cache<K, V>::get(K key) {
    if (look_up.find(key) != look_up.end()) {
        NodePtr node = look_up[key];
        detach(node);
        prepend(node);
        return node->value;
    }
    throw std::out_of_range("Key not found");
}

template<typename K, typename V>
void LRU_Cache<K, V>::detach(NodePtr node) {
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

template<typename K, typename V>
void LRU_Cache<K, V>::prepend(NodePtr node) {
    if (!m_head) {
        m_head = m_tail = node;
        return;
    }
    node->next = m_head;
    m_head->prev = node;
    m_head = node;
}

template<typename K, typename V>
void LRU_Cache<K, V>::trimCache() {
    if (!m_tail) return;

    NodePtr node_to_remove = m_tail;
    K key_to_remove = reverse_look_up[node_to_remove];

    detach(node_to_remove);

    look_up.erase(key_to_remove);
    reverse_look_up.erase(node_to_remove);

    delete node_to_remove;
    --m_length;
}

template class LRU_Cache<int, std::string>;
