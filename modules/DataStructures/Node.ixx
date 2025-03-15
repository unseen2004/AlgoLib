module;

export module Node;
export template<typename T>
struct node {
    T val;
    node<T> *next;
    node(T val) : val(val), next(nullptr) { }
};

export template<typename T>
struct Node {
    T val;
    Node<T> *left;
    Node<T> *right;
    Node(T v, Node<T> *left = nullptr, Node<T> *right = nullptr)
        : val(v), left(left), right(right) { }
};
