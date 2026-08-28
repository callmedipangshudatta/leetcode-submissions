class LRUCache {
    private:
        int cap;

        std::list<std::pair<int,int>> dll;

        std::unordered_map<int,std::list<std::pair<int,int>>::iterator> map;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end()){
            return -1;
        }
        dll.splice(dll.begin(),dll,map[key]);

        return map[key]->second;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            map[key]->second = value;

            //move the updated node to the front(MRU)
            dll.splice(dll.begin(),dll,map[key]);
            return;
        }

        //the key is new but the cache is full
        if(dll.size()==cap){
            int lru_key = dll.back().first;

            dll.pop_back();
            map.erase(lru_key);
        }

        dll.push_front({key,value});
        map[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */