#include "../../include/DataStructures/AVLTree.h"

template<typename T>
AVLTree<T>::Node::Node(T data) : m_data(data), m_left(nullptr), m_right(nullptr), m_height(1) {}

template<typename T>
AVLTree<T>::AVLTree() : m_root(nullptr) {}

template<typename T>
AVLTree<T>::~AVLTree() {
    clear(m_root);
}

template<typename T>
void AVLTree<T>::insert(T value) {
    m_root = insert(m_root, value);
}

template<typename T>
bool AVLTree<T>::remove(T value) {
    if (contains(value)) {
        m_root = remove(m_root, value);
        return true;
    }
    return false;
}

template<typename T>
bool AVLTree<T>::contains(T value) const {
    return contains(m_root, value);
}

template<typename T>
int AVLTree<T>::getHeight() const {
    return getHeight(m_root);
}

template<typename T>
void AVLTree<T>::printInOrder() const {
    printInOrder(m_root);
    std::cout << std::endl;
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::insert(Node* node, T value) {
    if (!node) return new Node(value);

    if (value < node->m_data) {
        node->m_left = insert(node->m_left, value);
    } else if (value > node->m_data) {
        node->m_right = insert(node->m_right, value);
    } else {
        return node;
    }

    node->m_height = 1 + std::max(getHeight(node->m_left), getHeight(node->m_right));

    return balance(node);
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::remove(Node* node, T value) {
    if (!node) return nullptr;

    if (value < node->m_data) {
        node->m_left = remove(node->m_left, value);
    } else if (value > node->m_data) {
        node->m_right = remove(node->m_right, value);
    } else {
        if (!node->m_left || !node->m_right) {
            Node* temp = node->m_left ? node->m_left : node->m_right;
            delete node;
            return temp;
        }

        Node* minNode = getMinNode(node->m_right);
        node->m_data = minNode->m_data;
        node->m_right = remove(node->m_right, minNode->m_data);
    }

    node->m_height = 1 + std::max(getHeight(node->m_left), getHeight(node->m_right));
    return balance(node);
}

template<typename T>
bool AVLTree<T>::contains(Node* node, T value) const {
    if (!node) return false;

    if (value < node->m_data) {
        return contains(node->m_left, value);
    } else if (value > node->m_data) {
        return contains(node->m_right, value);
    }
    return true;
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::balance(Node* node) {
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor < -1) {
        if (getBalanceFactor(node->m_left) > 0) {
            node->m_left = rotateLeft(node->m_left);
        }
        return rotateRight(node);
    }

    if (balanceFactor > 1) {
        if (getBalanceFactor(node->m_right) < 0) {
            node->m_right = rotateRight(node->m_right);
        }
        return rotateLeft(node);
    }

    return node;
}

template<typename T>
int AVLTree<T>::getBalanceFactor(Node* node) const {
    if (!node) return 0;
    return getHeight(node->m_right) - getHeight(node->m_left);
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateLeft(Node* node) {
    Node* newRoot = node->m_right;
    node->m_right = newRoot->m_left;
    newRoot->m_left = node;

    node->m_height = 1 + std::max(getHeight(node->m_left), getHeight(node->m_right));
    newRoot->m_height = 1 + std::max(getHeight(newRoot->m_left), getHeight(newRoot->m_right));

    return newRoot;
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::rotateRight(Node* node) {
    Node* newRoot = node->m_left;
    node->m_left = newRoot->m_right;
    newRoot->m_right = node;

    node->m_height = 1 + std::max(getHeight(node->m_left), getHeight(node->m_right));
    newRoot->m_height = 1 + std::max(getHeight(newRoot->m_left), getHeight(newRoot->m_right));

    return newRoot;
}

template<typename T>
int AVLTree<T>::getHeight(Node* node) const {
    return node ? node->m_height : 0;
}

template<typename T>
int AVLTree<T>::max(int a, int b) const {
    return (a > b) ? a : b;
}

template<typename T>
void AVLTree<T>::printInOrder(Node* node) const {
    if (!node) return;

    printInOrder(node->m_left);
    std::cout << node->m_data << " ";
    printInOrder(node->m_right);
}

template<typename T>
typename AVLTree<T>::Node* AVLTree<T>::getMinNode(Node* node) const {
    while (node && node->m_left) {
        node = node->m_left;
    }
    return node;
}

template<typename T>
void AVLTree<T>::clear(Node* node) {
    if (!node) return;

    clear(node->m_left);
    clear(node->m_right);
    delete node;
}
