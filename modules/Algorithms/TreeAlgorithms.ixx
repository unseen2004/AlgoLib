module;
import <vector>;
import Node;
import Queue;


export module TreeAlgorithms;
export template<typename T>
bool compareTrees(Node<T> *a, Node<T> *b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    if (a->val != b->val) return false;
    return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
}

export template<typename T>
bool breadthFirstSearch(Node<T> *head, T target) {
    if (!head) return false;
    Queue<Node<T> *> q;
    q.enqueue(head);
    while (!q.is_empty()) {
        Node<T> *curr = q.peek();
        q.dequeue();
        if (curr->val == target) return true;
        if (curr->left) q.enqueue(curr->left);
        if (curr->right) q.enqueue(curr->right);
    }
    return false;
}

export template<typename T>
bool depthFirstSearch(Node<T> *head, T target) {
    if (!head) return false;
    if (head->val == target) return true;
    return depthFirstSearch(head->left, target) || depthFirstSearch(head->right, target);
}

export template<typename T>
std::vector<T> treePreOrderTraversal(Node<T> *node, std::vector<T> &path) {
    if (!node) return path;
    path.push_back(node->val);
    treePreOrderTraversal(node->left, path);
    treePreOrderTraversal(node->right, path);
    return path;
}

export template<typename T>
std::vector<T> preOrderTraversal(Node<T> *head) {
    std::vector<T> path;
    return treePreOrderTraversal(head, path);
}