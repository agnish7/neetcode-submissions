class LRUCache {
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>:: iterator> cacheMap;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(!cacheMap.count(key)) return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheList.front().second;
    }
    
    void put(int key, int value) {
        if(cacheMap.count(key)) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheList.front().second = value;
            return;
        }

        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();

        if(cacheList.size() > cap) {
            cacheMap.erase(cacheList.back().first);
            cacheList.pop_back();
        }
    }
};
