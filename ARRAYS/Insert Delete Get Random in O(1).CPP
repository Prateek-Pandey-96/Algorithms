// 380. Insert Delete GetRandom O(1)

class RandomizedSet {
public:
    // we will maintain an imaginary data structure
    unordered_map<int, int> pos;
    vector<int> elements;
    
    // initialize empty structure
    RandomizedSet() {
        pos.clear();
        elements.clear();
    }

    int getSize(){
        return elements.size();
    }

    bool insert(int val) {
        if(pos.contains(val))
            return false;
        elements.push_back(val);
        pos[val] = getSize()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!pos.contains(val))
            return false;
        int idx = pos[val];
        elements[idx] = elements[getSize()-1];
        pos[elements[idx]] = idx;
        elements.pop_back();
        pos.erase(val);     
        return true;
    }
    
    // always return a random element from unique array
    int getRandom() {
        int rand_idx = rand() % getSize();
        return elements[rand_idx];
    }
};