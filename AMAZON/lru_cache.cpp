/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );*/


//put(1, 1);
//put(2, 2);
//get(1);       // returns 1
//put(3, 3);    // evicts key 2
//get(2);       // returns -1 (not found)
//put(4, 4);    // evicts key 1
//get(1);       // returns -1 (not found)
//get(3);       // returns 3
//get(4);       // returns 4


class LRUCache {
public:
    
    int capacity_=0;
    list<int> keys_put;
    unordered_map<int,pair<int,list<int>::iterator>> map_get; 
    
    LRUCache(int capacity) {
        capacity_=capacity;
    }
    
    int get(int key) {
        auto it=map_get.find(key);
        if(it==map_get.end())
            return -1;
        
        helper_fun(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it=map_get.find(key);
        if(it!=map_get.end())
            helper_fun(it);
        else
        {
            if(map_get.size()==capacity_)
            {
                map_get.erase(keys_put.back());
                keys_put.pop_back();
            }
            keys_put.push_front(key);
            map_get[key]={value,keys_put.begin()};
        }
        map_get[key]={value,keys_put.begin()};
    }
    
    void helper_fun(unordered_map<int,pair<int,list<int>::iterator>>::iterator itr)
    {
        int key=itr->first;
        keys_put.erase(itr->second.second);
        keys_put.push_front(key);
        itr->second.second=keys_put.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
