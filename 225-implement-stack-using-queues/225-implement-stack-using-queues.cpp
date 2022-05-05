class MyStack {
public:
    int len;
    queue<int> q;
    int _top;
    MyStack() {
        len = 0;
        _top = -1;
    }
    
    void push(int x) {
        q.push(x);
        len++;
        _top = x;
    }
    
    int pop() {
        if(len == 0){
            _top = -1;
            return -1;
        }
        int p = len;
        cout<<p<<endl;
        while(p > 1){
            int l = q.front();
            q.pop();
            q.push(l);
            _top = l;
            p--;
        }
        len--;
        p = q.front();
        q.pop();
        return p;
    }
    
    int top() {
        return _top;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */