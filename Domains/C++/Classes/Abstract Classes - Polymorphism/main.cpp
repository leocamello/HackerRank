class LRUCache : Cache {
    public:
    LRUCache(int capacity) {
        cp = capacity;
    }

    void set(int key, int value) {
        map<int, Node*>::iterator it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            node->value = value;
        }
        else {
            if (mp.size() == cp) {
                it = mp.find(tail->key);
                tail = tail->prev;
                tail->next = NULL;
                mp.erase(it);
            }

            Node* node = new Node(key, value);
            node->prev = NULL;
            if (mp.size() > 0) {
                node->next = head;
                head->prev = node;
            }
            else {
                node->next = NULL;
                tail = node;
            }
            head = node;

            mp[key] = node;
        }
    }

    int get(int key) {
        map<int, Node*>::iterator it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            if (node != head) {
                if (node != tail) {
                    node->next->prev = node->prev;
                    node->prev->next = node->next;
                }
                else {
                    tail = node->prev;
                    tail->next = NULL;
                }
                node->next = head;
                node->prev = NULL;
                head = node;
            }
            return node->value;
        }
        else {
            return -1;
        }
    }
};
