#include <bits/stdc++.h>
using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if (!root)
            return str;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur)
                str.append("#,");
            else {
                str.append(to_string(cur->val) + ",");
            }
            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);//stringstream associates a string object. 
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            // inserting leftnode value
            getline(s, str, ',');
            if (str == "#")
                cur->left = NULL;
            else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                cur->left = leftNode;
                q.push(leftNode);
            }
            // inserting rightNode value
            getline(s, str, ',');
            if (str == "#")
                cur->right = NULL;
            else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                cur->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Time and space complexity
// tc:- O(n)
// sc:- O(n)