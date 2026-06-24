class ArrayQueue {
public:
    int arr[1000];
    int front;
    int rear;

    ArrayQueue() {
        front=0;
        rear=-1;
    }
    
    void push(int x) {
        rear++;
        arr[rear]=x;
    }
    
    int pop() {
        if(isEmpty()) return -1;
        int x=arr[front];
        front++;
        return x;
    }
    
    int peek() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    bool isEmpty() {
        return front>rear;
    }
};
