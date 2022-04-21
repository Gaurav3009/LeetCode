class MyHashSet {
public:
    vector<int> vec;
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(vec.begin(), vec.end(), key) == vec.end()){
            vec.push_back(key);
        }
    }
    
    void remove(int key) {
        vector<int>::iterator it = find(vec.begin(), vec.end(), key);
        if(it != vec.end()){
            vec.erase(it);
        }
    }
    
    bool contains(int key) {
        if(find(vec.begin(), vec.end(), key) != vec.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */