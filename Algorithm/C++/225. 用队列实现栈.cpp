class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}
    
    void push(int x) {
        int n = q.size();
        q.push(x);

        for(int i = 0; i<n; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};