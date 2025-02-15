

/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class LRUCache {
 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->pre = head;
  }

  int get(int key) {
    Node* node;
    if (cache.find(key) != cache.end()) {
      moveToHead(key);
      return cache[key]->value;
    }
    return -1;
  }

  void put(int key, int value) {
    // 如果已在缓存中，只更改值,并移到表头
    if (cache.find(key) != cache.end()) {
      cache[key]->value = value;
      moveToHead(key);
    } else {
      insert(key, value);
    }
  }

 private:
  struct Node {
    int key;
    int value;
    Node* pre, *next;
    Node(int k, int v) : key(k), value(v),pre(nullptr),next(nullptr) {}
  };
  int capacity;
  unordered_map<int, Node*> cache;
  Node *head, *tail;
  // 在头部的节点是最近最常被访问的
  void insertAtHead(Node* node) {
    node->next = head->next;
    node->pre = head;
    head->next->pre = node;
    head->next = node;
  }
  void moveToHead(int key) {
    Node* node = cache[key];
    removeNode(node);
    insertAtHead(node);
  }
  void removeNode(Node* node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
  }
  void removeAtTail() {
    Node* node = tail->pre;
    removeNode(node);
    cache.erase(node->key);
    delete node; //cache中的node是new出来的，erase只会删除指针，需要手动释放
  }
  void insert(int key, int value) {
    Node* node = new Node(key, value);
    if (cache.size() == capacity) {
      removeAtTail();
    }
    insertAtHead(node);
    cache[key] = node;
  }
};
// int main() {
//   LRUCache* lru = new LRUCache(3);
//   lru->put(3, 3);
//   lru->put(1, 1);
//   lru->get(1);
// }
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
