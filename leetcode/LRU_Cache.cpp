// ────────────────────────────────────────────────────────────
// Problem : LRU Cache
// Platform: LeetCode
// URL     : https://leetcode.com/problems/lru-cache/submissions/2046880038/
// Language: cpp
// Date    : 6/26/2026, 7:25:27 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(??)
// Space Complexity: O(??)
// ────────────────────────────────────────────────────────────

class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* nxt;
        Node(int k,int v){
            key=k;
            val=v;
            prev=nullptr;
            nxt=nullptr;
        }
    };

    unordered_map<int,Node*> mp;
    int cap;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap=capacity;
        
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->nxt=tail;
        tail->prev=head;

        mp.clear();
    }

    void delNode(Node* node){
        Node* before=node->prev;
        Node* after=node->nxt;
        before->nxt=after;
        after->prev=before;
    }

    void insAfterHead(Node* node){
        Node* afterHead=head->nxt;
        head->nxt=node;
        node->prev=head;
        node->nxt=afterHead;
        afterHead->prev=node;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
        Node* node=mp[key];
        delNode(node);
        insAfterHead(node);
        return node->val;
        }else{
            return -1;
        }
    }
    void put(int key, int value) {
    if(mp.find(key)!=mp.end()) {
        Node* node = mp[key];
        node->val = value;
        delNode(node);
        insAfterHead(node);
    }
    else {
        if(mp.size()==cap) {
            Node* lastNode = tail->prev;
            mp.erase(lastNode->key);
            delNode(lastNode);
            delete lastNode;
        }
        Node* node = new Node(key,value);
        mp[key] = node;
        insAfterHead(node);
    }
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */