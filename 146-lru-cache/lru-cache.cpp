class LRUCache {
    private:

        int cap;

        using ListType = std::list<std::pair<int,int>>;

        ListType dll;

        //key,value 
        std::unordered_map<int,ListType::iterator> map;

public:

    //constructor
    //this tells LRUCche that it has capacity of 2 items
    LRUCache(int capacity) {
        cap = capacity;
    }
    

    int get(int key) {
        
        if(map.find(key)==map.end()){
            return -1;
        }

        // But remember the golden rule of an LRU Cache: Any time we touch an item, it becomes the Most Recently Used.
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

            //dll.back().first grabs the key out of the {key, value} pair sitting at the back of the list.
            int lru_key = dll.back().first;

            //dll.pop_back() destroys the node, removing it from the list.
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