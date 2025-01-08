#include "../../include/DataStructures/BST.h"

template <typename T>
BST<T>::Node::Node(T data) : m_data(data), m_left(nullptr), m_right(nullptr) {}

template <typename T>
BST<T>::BST() : m_root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    clear(m_root);
}

template <typename T>
void BST<T>::insert(T value) {
    m_root = insert(m_root, value);
}

template <typename T>
bool BST<T>::remove(T value) {
    if (contains(m_root, value)) {
        m_root = remove(m_root, value);
        return true;
    }
    return false;
}

template <typename T>
bool BST<T>::contains(T value) const {
    return contains(m_root, value);
}

template <typename T>
T BST<T>::getMin() const {
    if (m_root == nullptr) {
        throw std::runtime_error("The tree is empty.");
    }
    return getMinNode(m_root)->m_data;
}

template <typename T>
T BST<T>::getMax() const {
    if (m_root == nullptr) {
        throw std::runtime_error("The tree is empty.");
    }
    return getMaxNode(m_root)->m_data;
}

template <typename T>
int BST<T>::getHeight() const {
    return getHeight(m_root);
}

template <typename T>
void BST<T>::printInOrder() const {
    printInOrder(m_root);
}

template <typename T>
typename BST<T>::Node* BST<T>::insert(Node* node, T value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->m_data) {
        node->m_left = insert(node->m_left, value);
    } else if (value > node->m_data) {
        node->m_right = insert(node->m_right, value);
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::remove(Node* node, T value) {
    if (node == nullptr) {
        return node;
    }
    if (value < node->m_data) {
        node->m_left = remove(node->m_left, value);
    } else if (value > node->m_data) {
        node->m_right = remove(node->m_right, value);
    } else {
        if (node->m_left == nullptr) {
            Node* temp = node->m_right;
            delete node;
            return temp;
        } else if (node->m_right == nullptr) {
            Node* temp = node->m_left;
            delete node;
            return temp;
        }
        Node* temp = getMinNode(node->m_right);
        node->m_data = temp->m_data;
        node->m_right = remove(node->m_right, temp->m_data);
    }
    return node;
}

template <typename T>
bool BST<T>::contains(Node* node, T value) const {
    if (node == nullptr) {
        return false;
    }
    if (value < node->m_data) {
        return contains(node->m_left, value);
    } else if (value > node->m_data) {
        return contains(node->m_right, value);
    }
    return true;
}

template <typename T>
typename BST<T>::Node* BST<T>::getMinNode(Node* node) const {
    Node* current = node;
    while (current && current->m_left != nullptr) {
        current = current->m_left;
    }
    return current;
}

template <typename T>
typename BST<T>::Node* BST<T>::getMaxNode(Node* node) const {
    Node* current = node;
    while (current && current->m_right != nullptr) {
        current = current->m_right;
    }
    return current;
}

template <typename T>
int BST<T>::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getHeight(node->m_left);
    int rightHeight = getHeight(node->m_right);
    return std::max(leftHeight, rightHeight) + 1;
}

template <typename T>
void BST<T>::printInOrder(Node* node) const {
    if (node != nullptr) {
        printInOrder(node->m_left);
        std::cout << node->m_data << " ";
        printInOrder(node->m_right);
    }
}

template <typename T>
void BST<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->m_left);
        clear(node->m_right);
        delete node;
    }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;

