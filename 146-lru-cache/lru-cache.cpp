class LRUCache {
private:
    int cap;
    std::list<std::pair<int,int>> dll;
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> cache;
public:
    LRUCache(int capacity) {
        //how to intialize the LRU Cche with positive size capacity
        if(capacity > 0 ){
            cap = capacity;
        }
    }
    
    int get(int key) {
        //to get the value and mark it as "Most Recently Used"
        if(cache.find(key) == cache.end()){
            return -1;
        }
        dll.splice(dll.begin(),dll,cache[key]);
        return cache[key]->second;
    }
    
    
    void put(int key, int value) {
        //how to update the value of key if key exist
        if(cache.find(key) != cache.end()){
            cache[key]->second = value;
            dll.splice(dll.begin(),dll,cache[key]);
            return;
        }

        if(cache.size()==cap){
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