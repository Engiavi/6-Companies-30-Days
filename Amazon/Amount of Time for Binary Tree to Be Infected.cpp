#include<bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        // Step 1: Finding the parent of each node using a parent map
        unordered_map<int, TreeNode*> parentMap;
        findParents(root, nullptr, parentMap);
        
        // Step 2: BFS starting from the "start" node
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        
        TreeNode* startNode = findNode(root, start);
        q.push(startNode);
        visited[startNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check left child
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                
                // Check right child
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                // Check parent
                TreeNode* parent = parentMap[node->val];
                if (parent && !visited[parent]) {
                    q.push(parent);
                    visited[parent] = true;
                }
            }
            
            time++;
        }
        
        return time - 1;  // Since the time starts from the given start node
    }
    
private:
    // Helper function to find the parent of each node
    void findParents(TreeNode* node, TreeNode* parent, unordered_map<int, TreeNode*>& parentMap) {
        if (!node) return;
        
        if (parent) {
            parentMap[node->val] = parent;
        }
        
        findParents(node->left, node, parentMap);
        findParents(node->right, node, parentMap);
    }
    
    // Helper function to find a node with a specific value
    TreeNode* findNode(TreeNode* root, int val) {
        if (!root) return nullptr;
        if (root->val == val) return root;
        
        TreeNode* leftSearch = findNode(root->left, val);
        if (leftSearch) return leftSearch;
        
        TreeNode* rightSearch = findNode(root->right, val);
        if (rightSearch) return rightSearch;
        
        return nullptr;
    }
};
// Time and space complexity
// tc:- O(n)
// sc:- O(n)