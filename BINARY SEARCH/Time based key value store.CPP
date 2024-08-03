// 981. Time Based Key-Value Store


class TimeMap {
public:
    unordered_map<string, map<int, string>> hashMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        hashMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = hashMap[key].upper_bound(timestamp);
        if(it == hashMap[key].begin())
            return "";
        it--;
        return it->second;;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */