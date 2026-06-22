class Solution{
public:

    vector<int> heap;
    int size = 0;


    void initializeHeap(){
        heap.clear();
        size = 0;
    }


    void insert(int key){

        heap.push_back(key);
        size++;

        int i = size - 1;

        // heapify up
        while(i > 0){

            int parent = (i-1)/2;

            if(heap[parent] < heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else{
                break;
            }
        }
    }


    void changeKey(int index, int new_val){

        int old = heap[index];

        heap[index] = new_val;


        // increase key
        if(new_val > old){

            while(index > 0){

                int parent = (index-1)/2;

                if(heap[parent] < heap[index]){
                    swap(heap[parent], heap[index]);
                    index = parent;
                }
                else
                    break;
            }
        }


        // decrease key
        else{

            while(true){

                int left = 2*index + 1;
                int right = 2*index + 2;

                int largest = index;


                if(left < size && heap[left] > heap[largest])
                    largest = left;


                if(right < size && heap[right] > heap[largest])
                    largest = right;


                if(largest != index){
                    swap(heap[index], heap[largest]);
                    index = largest;
                }
                else
                    break;
            }
        }
    }


    void extractMax(){

        if(size == 0)
            return;


        heap[0] = heap[size-1];

        heap.pop_back();
        size--;


        int i = 0;


        // heapify down
        while(true){

            int left = 2*i + 1;
            int right = 2*i + 2;

            int largest = i;


            if(left < size && heap[left] > heap[largest])
                largest = left;


            if(right < size && heap[right] > heap[largest])
                largest = right;


            // if both children equal, choose LEFT child
            if(left < size && right < size &&
               heap[left] == heap[right] &&
               heap[left] > heap[i]){

                largest = left;
            }


            if(largest != i){

                swap(heap[i], heap[largest]);
                i = largest;
            }
            else
                break;
        }
    }


    bool isEmpty(){

        return size == 0;
    }


    int getMax(){

        if(size == 0)
            return -1;

        return heap[0];
    }


    int heapSize(){

        return size;
    }
};
