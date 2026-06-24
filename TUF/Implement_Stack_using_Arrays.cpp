class ArrayStack {
public:
    int arr[1000];
    int topIdx;

    ArrayStack() {
        topIdx=-1;
    }
    
    void push(int x) {
        topIdx++;
        arr[topIdx]=x;
    }
    
    int pop() {
        if(isEmpty()) return -1;
        int x=arr[topIdx];
        topIdx--;
        return x;
    }
    
    int top() {
        if(isEmpty()) return -1;
        return arr[topIdx];
    }
    
    bool isEmpty() {
        return topIdx==-1;
    }
};
