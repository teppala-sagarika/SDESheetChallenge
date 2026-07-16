// ────────────────────────────────────────────────────────────
// Problem : Clone Graph
// Platform: LeetCode
// URL     : https://leetcode.com/problems/clone-graph/submissions/2070185600/
// Language: cpp
// Date    : 7/16/2026, 10:34:33 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(V + E)
// Space Complexity: O(V + E)
// Notes           : bfs
// ────────────────────────────────────────────────────────────

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*> mp;
    void bfs(queue<Node*> q){
        while(!q.empty()){
            Node* node=q.front();
            Node* cloneNode=mp[node];
            q.pop();
            for(Node* n:node->neighbors){
                if(mp.find(n)==mp.end()){
                    //not in map
                    Node* clone=new Node(n->val);
                    mp[n]=clone;
                    cloneNode->neighbors.push_back(clone);

                    q.push(n);
                }
                else{
                    cloneNode->neighbors.push_back(mp[n]);
                }
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node* clone=new Node(node->val);
        mp[node]=clone;

        queue<Node*> q;
        q.push(node);

        bfs(q);

        return clone;
    }
};