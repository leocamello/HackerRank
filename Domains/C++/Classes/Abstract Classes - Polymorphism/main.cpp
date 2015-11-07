class LRUCache : Cache {
    public:
    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
    }

    void set(int key, int value) {
        map<int, Node*>::iterator it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            node->value = value;
        }
        else {
            if (cp > 0) {
                if (mp.size() == cp) {
                    it = mp.find(tail->key);
                    if (head == tail) {
                        head = NULL;
                        tail = NULL;
                    }
                    else {
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                    delete it->second;
                    mp.erase(it);
                }

                Node* node = new Node(key, value);
                mp[key] = node;

                if (head == NULL && tail == NULL) {
                    tail = node;
                }
                else {
                    head->prev = node;
                    node->next = head;
                }

                head = node;
            }
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
                head->prev = node;
                head = node;
            }
            return node->value;
        }
        else {
            return -1;
        }
    }
};
