// ────────────────────────────────────────────────────────────
// Problem : LFU Cache
// Platform: LeetCode
// URL     : https://leetcode.com/problems/lfu-cache/description/
// Language: cpp
// Date    : 6/26/2026, 10:30:35 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(??)
// Space Complexity: O(??)
// ────────────────────────────────────────────────────────────

class LFUCache {
public:

    struct Node {
        int key, val, cnt;
        Node *nxt, *prev;

        Node(int k, int v) {
            key = k;
            val = v;
            cnt = 1;
            nxt = nullptr;
            prev = nullptr;
        }
    };


    struct List {
        int size;
        Node *head, *tail;

        List() {
            head = new Node(0,0);
            tail = new Node(0,0);

            head->nxt = tail;
            tail->prev = head;

            size = 0;
        }


        void add(Node* node) {

            Node* temp = head->nxt;

            node->nxt = temp;
            node->prev = head;

            head->nxt = node;
            temp->prev = node;

            size++;
        }


        void del(Node* node) {

            Node* before = node->prev;
            Node* after = node->nxt;

            before->nxt = after;
            after->prev = before;

            size--;
        }
    };


    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqMp;

    int maxSize;
    int curSize;
    int minFreq;


    LFUCache(int capacity) {

        maxSize = capacity;
        curSize = 0;
        minFreq = 0;
    }


    void updateFreqListMap(Node* node) {

        int oldFreq = node->cnt;

        // remove from old frequency list
        freqMp[oldFreq]->del(node);


        // update minimum frequency
        if(oldFreq == minFreq && freqMp[oldFreq]->size == 0) {
            minFreq++;
        }


        // increase frequency
        node->cnt++;


        // add to new frequency list
        if(freqMp.find(node->cnt) == freqMp.end()) {
            freqMp[node->cnt] = new List();
        }


        freqMp[node->cnt]->add(node);
    }



    int get(int key) {

        if(keyNode.find(key) == keyNode.end()) {
            return -1;
        }


        Node* node = keyNode[key];

        int value = node->val;


        updateFreqListMap(node);


        return value;
    }



    void put(int key, int value) {


        if(maxSize == 0)
            return;



        // key already exists
        if(keyNode.find(key) != keyNode.end()) {


            Node* node = keyNode[key];

            node->val = value;


            updateFreqListMap(node);


        }

        else {


            // cache full
            if(curSize == maxSize) {


                List* list = freqMp[minFreq];


                Node* delNode = list->tail->prev;


                keyNode.erase(delNode->key);


                list->del(delNode);


                curSize--;
            }



            curSize++;


            minFreq = 1;



            if(freqMp.find(1) == freqMp.end()) {

                freqMp[1] = new List();

            }


            Node* node = new Node(key,value);


            freqMp[1]->add(node);


            keyNode[key] = node;

        }

    }
};