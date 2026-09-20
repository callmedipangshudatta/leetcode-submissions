class LRUCache {
    int cap;
    std::list<pair<int,int>> dll;
    std::unordered_map<int, std::list<pair<int,int>>:: iterator> cache;
public:
    LRUCache(int capacity) {
        if(capacity>0){
            cap = capacity;
        }
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        dll.splice(dll.begin(),dll,cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            cache[key]->second = value;
            dll.splice(dll.begin(),dll,cache[key]);
            return;
        }
        if(cache.size() == cap){
            int lru_key = dll.back().first;
            cache.erase(lru_key);
            dll.pop_back();
        }
        dll.push_front({key,value});
        cache[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */