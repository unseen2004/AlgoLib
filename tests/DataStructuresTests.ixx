module;

import <iostream>;
import Heap;
import LinkedList;
import DoubleLinkedList;
import LRU_Cache;
import Queue;
import Stack;
import RedBlackTree;
import Trie;
import AVLTree;
import BST;
import BTree;


export module DataStructureTests;
export namespace dataStructureTests {

auto testHeap() -> void {
    std::cout << "Testing Heap:" << std::endl;
    Heap<int> h(true);
    h.insert(5);
    h.insert(2);
    h.insert(8);
    std::cout << "Deleted top: " << h.deleteTop() << std::endl << std::endl;
}

auto testLinkedList() -> void {
    std::cout << "Testing LinkedList:" << std::endl;
    LinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);
    std::cout << "Searching 20: " << (list.search(20) ? "found" : "not found") << std::endl << std::endl;
}

auto testDoubleLinkedList() -> void {
    std::cout << "Testing DoubleLinkedList:" << std::endl;
    DoubleLinkedList<int> dlist;
    dlist.push(1);
    dlist.push(2);
    dlist.push(3);
    std::cout << "Searching 2: " << (dlist.search(2) ? "found" : "not found") << std::endl;
    dlist.pop();
    std::cout << "After pop, searching 3: " << (dlist.search(3) ? "found" : "not found") << std::endl << std::endl;
}

auto testLRUCache() -> void {
    std::cout << "Testing LRU_Cache:" << std::endl;
    LRU_Cache<std::string, int> cache(3);
    cache.update("key1", 100);
    cache.update("key2", 200);
    cache.update("key3", 300);
    std::cout << "Value for key2: " << cache.get("key2") << std::endl;
    cache.update("key4", 400); // cache should trim one entry
    try {
        std::cout << "Attempting to get removed key1: " << cache.get("key1") << std::endl;
    } catch (const std::out_of_range &) {
        std::cout << "key1 not found" << std::endl;
    }
    std::cout << std::endl;
}

auto testQueue() -> void {
    std::cout << "Testing Queue:" << std::endl;
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << "Front: " << q.peek() << std::endl;
    q.dequeue();
    std::cout << "Front after dequeue: " << q.peek() << std::endl << std::endl;
}

auto testStack() -> void {
    std::cout << "Testing Stack:" << std::endl;
    Stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);
    std::cout << "Top: " << s.peek() << std::endl;
    s.pop();
    std::cout << "Top after pop: " << s.peek() << std::endl << std::endl;
}

auto testRedBlackTree() -> void {
    std::cout << "Testing RedBlackTree:" << std::endl;
    RedBlackTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    std::cout << "In-order traversal: ";
    tree.printInOrder();
    std::cout << std::endl;
}

auto testTrie() -> void {
    std::cout << "Testing Trie:" << std::endl;
    Trie<char> trie;
    trie.insert("hello");
    trie.insert("world");
    std::cout << "Searching for 'hello': " << (trie.search("hello") ? "found" : "not found") << std::endl;
    trie.erase("hello");
    std::cout << "After erasing, searching for 'hello': " << (trie.search("hello") ? "found" : "not found") << std::endl << std::endl;
}

auto testAVLTree() -> void {
    std::cout << "Testing AVLTree:" << std::endl;
    AVLTree<int> avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    std::cout << "In-order traversal: ";
    avl.printInOrder();
    std::cout << std::endl;
}

auto testBST() -> void {
    std::cout << "Testing BST:" << std::endl;
    BST<int> bst;
    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.insert(8);
    bst.insert(12);
    std::cout << "In-order traversal: ";
    bst.printInOrder();
    std::cout << std::endl;
}

void testBTree() {
    std::cout << "Testing BTree:" << std::endl;
    BTree<int> btree(3); // degree 3
    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);
    btree.insert(7);
    btree.insert(17);
    std::cout << "BTree in-order print:" << std::endl;
    btree.print();
    std::cout << std::endl;
}

auto runAll() -> void {
    testHeap();
    testLinkedList();
    testDoubleLinkedList();
    testLRUCache();
    testQueue();
    testStack();
    testRedBlackTree();
    testTrie();
    testAVLTree();
    testBST();
    testBTree();
}

} // namespace tests
