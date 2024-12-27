#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

template<typename T>
struct Node {
    T val;
    Node<T> *left;
    Node<T> *right;

    Node(T x) : val(x), left(nullptr), right(nullptr) {
    }
};

template<typename T>
bool compareTrees(Node<T> *a, Node<T> *b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }
    if (a == nullptr || b == nullptr) {
        return false;
    }
    if (a->val != b->val) {
        return false;
    }

    return compareTrees(a->left, b->left) && compareTrees(a->right, b->right);
}

template<typename T>
bool breadthFirstSearch(Node<T> *head, T target) {
    if (!head) {
        return false;
    }

    std::queue<Node<T> *> q;
    q.push(head);

    while (!q.empty()) {
        Node<T> *curr = q.front();
        q.pop();

        if (curr->val == target) {
            return true;
        }

        if (curr->left) {
            q.push(curr->left);
        }

        if (curr->right) {
            q.push(curr->right);
        }
    }

    return false;
}

template<typename T>
std::vector<T> graphBFS(const std::vector<std::vector<T> > &graph, T source, T target) {
    std::vector<bool> seen(graph.size(), false);
    std::vector<T> prev(graph.size(), -1);

    seen[source] = true;
    std::queue<T> q;
    q.push(source);

    while (!q.empty()) {
        T curr = q.front();
        q.pop();

        if (curr == target) {
            break;
        }

        const std::vector<T> &adjs = graph[curr];
        for (size_t i = 0; i < adjs.size(); ++i) {
            if (adjs[i] == 0) {
                continue;
            }

            if (seen[i]) {
                continue;
            }

            seen[i] = true;
            prev[i] = curr;
            q.push(i);
        }
    }

    std::vector<T> out;
    if (prev[target] == -1) {
        return out;
    }

    for (T at = target; at != -1; at = prev[at]) {
        out.push_back(at);
    }
    std::reverse(out.begin(), out.end());
    return out;
}

template<typename T>
bool searchTree(Node<T> *node, T target) {
    if (!node) {
        return false;
    }
    if (node->val == target) {
        return true;
    }
    if (node->val < target) {
        return searchTree(node->next, target);
    } else {
        return searchTree(node->prev, target);
    }
}

template<typename T>
bool depthFirstSearch(Node<T> *head, T target) {
    return searchTree(head, target);
}

template<typename T>
bool graphDFSUtil(const std::vector<std::vector<std::pair<T, T> > > &graph, T curr, T target, std::vector<bool> &seen,
                  std::vector<T> &path) {
    if (seen[curr]) {
        return false;
    }

    seen[curr] = true;
    path.push_back(curr);

    if (curr == target) {
        return true;
    }

    const std::vector<std::pair<T, T> > &list = graph[curr];
    for (const auto &edge: list) {
        if (graphDFSUtil(graph, edge.first, target, seen, path)) {
            return true;
        }
    }

    path.pop_back();
    return false;
}

template<typename T>
std::vector<T> graphDFS(const std::vector<std::vector<std::pair<T, T> > > &graph, T source, T target) {
    std::vector<bool> seen(graph.size(), false);
    std::vector<T> path;

    graphDFSUtil(graph, source, target, seen, path);

    return path;
}

template<typename T>
using Edge = std::pair<T, T>;

template<typename T>
void dijkstraAlgorithm(T src, const std::vector<std::vector<Edge<T> > > &graph) {
    T n = graph.size();
    std::vector<T> dist(n, std::numeric_limits<T>::max());
    std::vector<bool> seen(n, false);

    dist[src] = 0;
    using Pair = std::pair<T, T>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<> > pq;
    pq.push({0, src});

    while (!pq.empty()) {
        T currDist = pq.top().first;
        T node = pq.top().second;
        pq.pop();

        if (seen[node]) continue;
        seen[node] = true;

        for (const auto &edge: graph[node]) {
            T v = edge.first;
            T weight = edge.second;

            if (!seen[v] && dist[v] > currDist + weight) {
                dist[v] = currDist + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

template<typename T>
std::vector<T> treePreOrderTraversal(Node<T> *node, std::vector<T> &path) {
    if (!node) {
        return path;
    }

    path.push_back(node->val);

    treePreOrderTraversal(node->left, path);
    treePreOrderTraversal(node->right, path);

    return path;
}

template<typename T>
std::vector<T> preOrderTraversal(Node<T> *head) {
    std::vector<T> path;
    return treePreOrderTraversal(head, path);
}

int partition(std::vector<int> &arr, int lo, int hi) {
    const int pivot = arr[hi];
    int idx = lo - 1;

    for (int i = lo; i < hi; ++i) {
        if (arr[i] <= pivot) {
            ++idx;
            std::swap(arr[i], arr[idx]);
        }
    }

    ++idx;
    std::swap(arr[hi], arr[idx]);

    return idx;
}

void quickSort(std::vector<int> &arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }

    int pivotIdx = partition(arr, lo, hi);
    quickSort(arr, lo, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, hi);
}
