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
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> nodemap;
        nodemap[node] = new Node(node->val);
        dfs(node, nodemap);
        return nodemap[node];
    }

    void dfs(Node* node, unordered_map<Node*, Node*> nodemap) {
        for(auto& neighbor: node->neighbors) {
            if(!nodemap.count(neighbor)) {
                nodemap[neighbor] = new Node(neighbor->val);
                dfs(neighbor, nodemap);
            }
            nodemap[node]->neighbors.push_back(nodemap[neighbor]);
        }
    }
};
