class MyHashMap {
public:
    vector<pair<int, int>> x;
    MyHashMap() {
    }
    
    void put(int key, int value) {
        for(int i = 0;i<x.size();i++){
            if(x[i].first == key){
                x[i].second = value;
                return;
            }
        }
        x.push_back({key, value});
    }
    
    int get(int key) {
        for(int i = 0;i<x.size();i++){
            if(x[i].first == key){
                return x[i].second;
            }
        }
        return -1;
    }
    void remove(int key) {
        for(int i = 0;i<x.size();i++){
            if(x[i].first == key){
                x.erase(x.begin() + i, x.begin() + i + 1);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */