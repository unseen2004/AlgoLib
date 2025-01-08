#ifndef B_TREE_H
#define B_TREE_H

#include <vector>
#include <iostream>

template <typename T>
class b_tree {
private:
    struct node {
        std::vector<T> m_keys;
        std::vector<node*> m_children;
        bool m_is_leaf;
        int m_degree;

        node(int degree, bool is_leaf);
    };

    node* m_root;
    int m_degree;

public:
    b_tree(int degree);

    void insert(const T& key);
    void remove(const T& key);
    bool search(const T& key) const;
    void print() const;

private:
    void insert_non_full(node* current_node, const T& key);
    void split_child(node* parent, int index, node* child);
    void remove_key(node* current_node, const T& key);
    T get_predecessor(node* current_node);
    T get_successor(node* current_node);
    void fill_node(node* current_node, int index);
    void borrow_from_prev(node* current_node, int index);
    void borrow_from_next(node* current_node, int index);
    void merge_nodes(node* current_node, int index);
    void print_node(node* current_node, int level) const;
    bool search_node(node* current_node, const T& key) const;
};

#endif // B_TREE_H
