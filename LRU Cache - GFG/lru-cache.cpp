//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class Node {
    public:
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->prev = this->next = NULL;
        }
};
class LRUCache
{
    private:
        int capacity;
        Node *head, *tail;
        map<int, Node*> hashMap;
        int count = 0;
    public:
    //Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int cap)
    {
        this->capacity = cap;
        this->head = new Node(0, 0);
        this->tail = new Node(0, 0);
        this->count = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    void setPriority(Node *curr) {
        curr->next = head->next;
        curr->next->prev = curr;
        head->next = curr;
        curr->prev = head;
    }
    int GET(int key)
    {
        if(hashMap.find(key) != hashMap.end()) {
            Node *curr = hashMap[key];
            if(curr->prev != head) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->next = curr->prev = NULL;
                setPriority(curr);
            }
            return curr->value;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(hashMap.find(key) != hashMap.end()) {
            Node *curr = hashMap[key];
            curr->value = value;
            if(curr->prev != head) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->next = curr->prev = NULL;
                setPriority(curr);
            }
            return ;
        }
        if(count == capacity) {
            Node *curr = tail->prev;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            hashMap.erase(curr->key);
            count--;
        }
        Node *curr = new Node(key, value);
        count++;
        hashMap[key] = curr;
        setPriority(curr);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends