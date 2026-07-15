#include <unordered_map>
using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    unordered_map<int, Node*> m;
    int capacity;

    Node *head;
    Node *tail;

    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Insert node right after head
    void addNode(Node *newNode) {
        Node *temp = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }

    // Remove node from the list
    void deleteNode(Node *delNode) {
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        Node *temp = m[key];
        int ans = temp->value;

        deleteNode(temp);
        addNode(temp);

        return ans;
    }

    void put(int key, int value) {

        // If key already exists
        if (m.find(key) != m.end()) {
            Node *existing = m[key];
            deleteNode(existing);
            m.erase(key);
            delete existing;
        }

        // Cache full -> remove LRU node
        if (m.size() == capacity) {
            Node *lru = tail->prev;

            deleteNode(lru);
            m.erase(lru->key);
            delete lru;
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */