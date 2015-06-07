class LRUCache{
public:
    struct entry {
        int key;
        int value;
        entry(int k, int v) {key = k; value = v;}
    };
    LRUCache(int capacity) {
        size = capacity;
    }
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        moveHead(key);
        return m[key]->value;
    }
    void set(int key, int value) {
        if (m.find(key) == m.end()) {
            entry e(key, value);
            if (lru.size() >= size) {
                m.erase(lru.back().key);
                lru.pop_back();
            }
            lru.push_front(e);
            m[key] = lru.begin();
        }
        else {
            m[key]->value = value;
            moveHead(key);
        }
    }
private:
    int size;
    list<entry> lru;
    unordered_map<int, list<entry>::iterator> m;
    void moveHead(int key) {
        auto newEntry = *m[key];
        lru.erase(m[key]);
        lru.push_front(newEntry);
        m[key] = lru.begin();
    }
};
