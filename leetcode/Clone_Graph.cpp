// ────────────────────────────────────────────────────────────
// Problem : Clone Graph
// Platform: LeetCode
// URL     : https://leetcode.com/problems/clone-graph/submissions/2070175034/
// Language: cpp
// Date    : 7/16/2026, 10:27:25 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(V + E)
// Space Complexity: O(V + E)
// Notes           : dfs
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
    void dfs(Node* node,Node* clone){
        for(Node* n:node->neighbors){
            if(mp.find(n)==mp.end()){
                //not in map
                Node* cloneNode=new Node(n->val);
                mp[n]=cloneNode;
                clone->neighbors.push_back(cloneNode);
                dfs(n,cloneNode);
            }else{
                clone->neighbors.push_back(mp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node* clone=new Node(node->val);
        mp[node]=clone;

        dfs(node,clone);

        return clone;
    }
};