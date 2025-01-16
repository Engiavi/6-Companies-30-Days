class Solution {
private:
    void findParents(TreeNode* node, TreeNode* parent,
                     unordered_map<int, TreeNode*>& parentMap) {
        if (!node)
            return;

        if (parent) {
            parentMap[node->val] = parent;
        }

        findParents(node->left, node, parentMap);
        findParents(node->right, node, parentMap);
    }
    TreeNode* findNode(TreeNode* root, int val) {
        if (!root)
            return nullptr;
        if (root->val == val)
            return root;

        TreeNode* leftSearch = findNode(root->left, val);
        if (leftSearch)
            return leftSearch;

        TreeNode* rightSearch = findNode(root->right, val);
        if (rightSearch)
            return rightSearch;

        return nullptr;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, TreeNode*> parentMap;
        findParents(root, nullptr, parentMap);
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
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                TreeNode* parent = parentMap[node->val];
                if (parent && !visited[parent]) {
                    q.push(parent);
                    visited[parent] = true;
                }
            }

            time++;
        }

        return time - 1;
    }
};
// time and space complexity
// tc: O(n), n is the number of nodes in the binary tree
// sc: O(n), for the parentMap and visited map