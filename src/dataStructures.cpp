#include <vector>
#include <algorithm> 


template <typename T>
class MinHeap {
private:
    int length;
    std::vector<T> data;

public:
    MinHeap() : length(0), data() {}

    ~MinHeap() {
        while (length > 0) {
            deleteMin();
        }
    }

    void insert(T n) {
        data.push_back(n);
        heapifyUp(length);
        ++length;
    }

    T deleteMin() {
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
        if (data[p] > data[idx]) {
            std::swap(data[p], data[idx]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int idx) {
        int lIdx = leftChild(idx);
        int rIdx = rightChild(idx);
        int smallest = idx;

        if (lIdx < length && data[lIdx] < data[smallest]) {
            smallest = lIdx;
        }

        if (rIdx < length && data[rIdx] < data[smallest]) {
            smallest = rIdx;
        }

        if (smallest != idx) {
            std::swap(data[idx], data[smallest]);
            heapifyDown(smallest);
        }
    }
}



template <typename T>
struct node {
    T m_val;
    node<T>* m_next;

    node(T val) : m_val(val), m_next(nullptr) {}
};

template <typename T>
class LinkedList {
    node<T>* m_head;
public: 
    LinkedList() : m_head(nullptr) {}

    ~LinkedList() {
        while (m_head) {
            pop();
        }
    }

    void add(T val) {
        node<T>* newNode = new node<T>(val);
        if (m_head == nullptr) {
            m_head = newNode;
        } else {
            node<T>* tmp = m_head;
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
            node<T>* tmp = m_head;
            while (tmp->m_next->m_next) {
                tmp = tmp->m_next;
            }
            delete tmp->m_next;
            tmp->m_next = nullptr;
        }
    }
};



template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node<T>* prev;

    Node(T v, Node<T>* next = nullptr, Node<T>* prev = nullptr)
        : val(v), next(next), prev(prev) {}
};

template <typename T>
class DoubleLinkedList {
    Node<T>* m_head;
    Node<T>* m_tail;
public: 
    DoubleLinkedList() : m_head(nullptr), m_tail(nullptr) {}

    ~DoubleLinkedList() {
        while (m_tail) {
            pop();
        }
    }

    void push(T val) {
        Node<T>* newNode = new Node<T>(val, nullptr, nullptr);
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
            Node<T>* toDel = m_tail;
            m_tail = m_tail->prev;
            m_tail->next = nullptr;
            delete toDel;
        }
    }
};


